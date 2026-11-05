#!/usr/bin/env python3
"""Check the original runtime scheduler and rebuilt C against a trace model.

Helpers use deterministic MIPS stubs. This covers scheduler ordering and clock
state, including empty/future queues and the equal-time pass counter; helper
implementations are outside the scope of this test. Exact bytes are a separate
gate in the runtime manifest.
"""
from pathlib import Path
from hashlib import sha1
import random
import struct
import tempfile
from n64dk.elf import Elf
from n64dk.emu import Machine
from n64dk.match.pipeline import BuildSpec, build
from n64dk.match.toolchain import load_config
from n64dk.rom import Rom
from survey_runtime_image import loader_mapping
from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
ENTRY, DELTA, SCRATCH = 0x800B4578, 0x7FF5C710, 0x80170000
SYMBOLS = {
    'runtimeFrameTime': 0x800F2774, 'runtimeStopFrame': 0x800F2770,
    'runtimeClockTime': 0x800F2744, 'runtimeDisplayState': 0x800F2720,
    'runtimeClockTicks': 0x800F272C, 'runtimeExitFlag': 0x800F2748,
    'runtimePriorityQueue': 0x800F26E0, 'runtimeOutputQueue': 0x800F26F4,
    'runtimeStageObject': 0x800F4D00, 'runtimeAudioObject': 0x800F1AE0,
}
HELPERS = {0x800AB024: 1, 0x800D5064: 2, 0x800BBBE0: 3,
           0x800AB140: 4, 0x800AB8C8: 5, 0x800D5108: 6, 0x800A30E8: 7}
FRAME, STOP, TICKS = 0x2774, 0x2770, 0x272C


def u32(value):
    return value & 0xffffffff


def i32(value):
    return (value + 0x80000000) % 0x100000000 - 0x80000000


def put(machine, address, data):
    offset = address & 0x1fffffff
    machine.ram[offset:offset + len(data)] = data


def words(machine, address, values):
    put(machine, address, struct.pack('>' + 'I' * len(values), *map(u32, values)))


def read(machine, address, count=1):
    return struct.unpack_from('>' + 'I' * count, machine.ram, address & 0x1fffffff)


def stub(kind):
    # t0 = scratch, t1 = trace index, t2 = trace row, t3 = runtime data page.
    code, labels, branches = [], {}, []
    def emit(op, rs, rt, imm):
        code.append((op << 26) | (rs << 21) | (rt << 16) | (imm & 0xffff))
    def addu(rd, rs, rt):
        code.append((rs << 21) | (rt << 16) | (rd << 11) | 0x21)
    def branch(op, rs, rt, label):
        branches.append((len(code), label)); emit(op, rs, rt, 0)
    def label(name):
        labels[name] = len(code)
    emit(15, 0, 8, SCRATCH >> 16)
    emit(35, 8, 9, 0)
    code.append((9 << 16) | (10 << 11) | (5 << 6))  # sll t2,t1,5
    addu(10, 8, 10)
    emit(9, 10, 10, 0x100)
    emit(9, 0, 12, kind)
    emit(43, 10, 12, 0)
    emit(43, 10, 4, 4)
    emit(43, 10, 5, 8)
    emit(15, 0, 11, 0x800F)
    for offset, field in ((12, FRAME), (16, STOP), (20, TICKS)):
        emit(35, 11, 12, field); emit(43, 10, 12, offset)
    emit(35, 8, 12, 4); emit(43, 10, 12, 24)
    emit(9, 9, 9, 1); emit(43, 8, 9, 0)
    if kind == 1:
        emit(35, 8, 2, 20)
    if kind == 3:
        emit(35, 8, 12, 4); emit(9, 12, 12, 1); emit(43, 8, 12, 4)
        emit(35, 8, 13, 8)
        code.append((13 << 21) | (12 << 16) | (14 << 11) | 0x2a)  # slt t6,limit,count
        branch(5, 14, 0, 'done'); code.append(0)
        emit(35, 8, 13, 12); emit(35, 11, 14, FRAME)
        addu(14, 14, 13); emit(43, 11, 14, FRAME)
    if kind == 6:
        emit(35, 8, 12, 4); emit(35, 8, 13, 16)
        branch(5, 12, 13, 'done'); code.append(0)
        emit(9, 0, 12, 1); emit(43, 11, 12, STOP)
    label('done')
    code.extend((0x03e00008, 0))
    for position, destination in branches:
        code[position] |= (labels[destination] - position - 1) & 0xffff
    return code


def model(case):
    clock, frame, display, count, deadline, ticks, exit_flag, pump_limit, pump_step, force_stop = case
    observed, stop, calls, trace = frame, 0, 0, []
    time, equal_passes = i32(clock + 256), 0
    def record(kind, a0=None, a1=None):
        trace.append((kind, a0, None if a1 is None else u32(a1), u32(frame), stop, u32(ticks), calls))
    if display and clock == observed:
        time = observed
        future = count == 0
        if count:
            record(1, SYMBOLS['runtimePriorityQueue'])
            future = deadline > observed
        if future:
            record(2, SYMBOLS['runtimeStageObject'])
    while observed >= time and not stop:
        if time == observed:
            stop = int(equal_passes == 0)
            equal_passes += 1
        else:
            stop = 0
        record(3)
        calls += 1
        if calls <= pump_limit:
            frame = i32(frame + pump_step)
        record(4, SYMBOLS['runtimePriorityQueue'], time)
        record(5, SYMBOLS['runtimeOutputQueue'])
        record(6, SYMBOLS['runtimeStageObject'])
        if calls == force_stop:
            stop = 1
        time = i32(time + 256)
        ticks = u32(ticks + 1)
        observed = frame
        assert calls <= 12, ('unbounded model', case)
    record(7, SYMBOLS['runtimeAudioObject'], frame >> 8)
    return trace, (u32(frame), stop, u32(ticks)), int(exit_flag == 0)


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    assert len(rom.data) == EXPECTED_SIZE and sha1(rom.data).hexdigest() == EXPECTED_SHA1
    original, rebuilt = Machine(rom), Machine(rom)
    start, address, length, _, _ = loader_mapping(rom)
    for machine in (original, rebuilt):
        put(machine, address, rom.data[start:start + length])
    with tempfile.TemporaryDirectory(prefix='sydney-runtime-frame-') as tmp:
        obj = build(ROOT / 'src/runtime/run_runtime_frame.c',
                    BuildSpec('sn', '-O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb'.split()),
                    load_config(ROOT), Path(tmp))
        symbols = dict(SYMBOLS)
        symbols.update({f'func_{address:08X}': address for address in HELPERS})
        put(rebuilt, ENTRY, Elf.load(obj).relocate('.text', {'.text': ENTRY}, symbols))
    for machine in (original, rebuilt):
        for address, kind in HELPERS.items():
            words(machine, address, stub(kind))
    cases = []
    for delta in (-512, -1, 0, 1, 256, 512, 1024):
        for display in (0, 1):
            for count, deadline in ((0, 0), (1, 511), (1, 512), (1, 513)):
                for pump_limit, force_stop in ((0, 0), (3, 0), (3, 3), (0, 1)):
                    for exit_flag in (0, 1):
                        cases.append((512, 512 + delta, display, count, deadline,
                                      0xfffffffe, exit_flag, pump_limit, 256, force_stop))
    rng = random.Random(2000)
    for _ in range(160):
        clock = rng.randrange(-2048, 2049)
        cases.append((clock, clock + rng.randrange(-3, 5) * 256, rng.randrange(2), rng.randrange(3),
                      clock + rng.randrange(-2, 3), rng.randrange(2**32), rng.randrange(3),
                      rng.randrange(4), rng.choice((0, 128, 256)), rng.randrange(5)))
    for index, case in enumerate(cases):
        expected_trace, expected_state, expected_return = model(case)
        clock, frame, display, count, deadline, ticks, exit_flag, pump_limit, pump_step, force_stop = case
        for machine in (original, rebuilt):
            put(machine, 0x800F2700, bytes(0x90))
            words(machine, SYMBOLS['runtimeClockTime'], [clock])
            words(machine, SYMBOLS['runtimeFrameTime'], [frame])
            words(machine, SYMBOLS['runtimeClockTicks'], [ticks])
            words(machine, SYMBOLS['runtimeDisplayState'], [display])
            words(machine, SYMBOLS['runtimeExitFlag'], [exit_flag])
            put(machine, SYMBOLS['runtimePriorityQueue'] + 12, struct.pack('>H', count))
            put(machine, SCRATCH, bytes(4096))
            words(machine, SCRATCH + 8, [pump_limit, pump_step, force_stop, deadline])
            reason = machine.call(ENTRY, (), max_steps=20000)
            assert reason == 'returned', (index, case, reason)
            assert machine.gpr[2] == expected_return, (index, case, 'return', machine.gpr[2])
            state = (read(machine, SYMBOLS['runtimeFrameTime'])[0],
                     read(machine, SYMBOLS['runtimeStopFrame'])[0], read(machine, SYMBOLS['runtimeClockTicks'])[0])
            assert state == expected_state, (index, case, 'state', state, expected_state)
            total = read(machine, SCRATCH)[0]
            actual = [read(machine, SCRATCH + 0x100 + row * 32, 7) for row in range(total)]
            assert len(actual) == len(expected_trace), (index, case, 'trace length', actual, expected_trace)
            for row, expected in zip(actual, expected_trace):
                assert all(value is None or value == observed for observed, value in zip(row, expected)), (index, case, row, expected)
    print(f'{len(cases)} cases: original and rebuilt MIPS agree with independent scheduler traces and clock state')


if __name__ == '__main__':
    main()
