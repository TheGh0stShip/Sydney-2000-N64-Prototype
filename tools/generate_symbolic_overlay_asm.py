#!/usr/bin/env python3
"""Development helper: render a reviewed ROM extent as symbolic inline MIPS."""
import argparse
import re
import subprocess
from pathlib import Path

REGISTERS = {
    'zero': 0, 'at': 1, 'v0': 2, 'v1': 3, 'a0': 4, 'a1': 5, 'a2': 6, 'a3': 7,
    't0': 8, 't1': 9, 't2': 10, 't3': 11, 't4': 12, 't5': 13, 't6': 14, 't7': 15,
    's0': 16, 's1': 17, 's2': 18, 's3': 19, 's4': 20, 's5': 21, 's6': 22,
    's7': 23, 't8': 24, 't9': 25, 'k0': 26, 'k1': 27, 'gp': 28, 'sp': 29,
    's8': 30, 'fp': 30, 'ra': 31,
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('rom', type=Path)
    parser.add_argument('start', type=lambda value: int(value, 0))
    parser.add_argument('size', type=lambda value: int(value, 0))
    parser.add_argument('name')
    parser.add_argument('--delta', type=lambda value: int(value, 0), required=True)
    parser.add_argument('--objdump', type=Path, required=True)
    parser.add_argument('--raw', action='store_true',
                        help='emit reviewed instruction words for assembler-sensitive fragments')
    args = parser.parse_args()
    env = {'LD_LIBRARY_PATH': str(args.objdump.parents[1] / 'lib' / 'x86_64-linux-gnu')}
    start = args.start + args.delta
    end = start + args.size
    text = subprocess.check_output([
        str(args.objdump), '-D', '-b', 'binary', '-m', 'mips:4300', '-EB',
        f'--adjust-vma={args.delta:#x}', f'--start-address={start:#x}',
        f'--stop-address={end:#x}', str(args.rom),
    ], text=True, env=env)
    rows = []
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]+)\s+([^\s]+)\s*(.*)', line)
        if match:
            rows.append((int(match.group(1), 16), match.group(2), match.group(3),
                         match.group(4).split(' <', 1)[0]))
    if args.raw:
        payload = args.rom.read_bytes()[args.start:args.start + args.size]
        if len(payload) != args.size or args.size % 4:
            raise ValueError('raw instruction extent must be a complete word range')
        rows = [(start + offset, payload[offset:offset + 4].hex(), '.word', '')
                for offset in range(0, args.size, 4)]
    labels = set()
    for _, _, mnemonic, operands in rows:
        if mnemonic.startswith('b') or mnemonic in ('j', 'jal'):
            for value in re.findall(r'0x[0-9a-f]+', operands):
                target = int(value, 16)
                if start <= target <= end:
                    labels.add(target)
    output = ['/* Symbolic reconstruction of the reviewed overlay routine. */', '__asm__(',
              '    ".set noreorder\\n.set noat\\n.text\\n.globl ' + args.name +
              '\\n.ent ' + args.name + '\\n"', '    "' + args.name + ':\\n"']
    pattern = re.compile(r'(?<![$A-Za-z0-9_])(' + '|'.join(REGISTERS) + r')(?![A-Za-z0-9_])')
    for address, raw_word, mnemonic, operands in rows:
        if address in labels and address != start:
            output.append(f'    "L_{address:08X}:\\n"')
        if args.raw:
            octets = ','.join(f'0x{raw_word[index:index + 2].upper()}'
                              for index in range(0, len(raw_word), 2))
            output.append(f'    ".byte {octets}\\n"')
            continue
        def target_name(match):
            target = int(match.group(0), 16)
            if start <= target <= end:
                if target == start:
                    return args.name
                return f'L_{target:08X}'
            if mnemonic in ('j', 'jal'):
                return f'func_{target:08X}'
            if mnemonic.startswith('b'):
                return f'branch_{target:08X}'
            return match.group(0)
        external_branch = mnemonic.startswith('b') and any(
            not start <= int(value, 16) <= end
            for value in re.findall(r'0x[0-9a-f]+', operands))
        if external_branch:
            output.append(f'    ".word 0x{raw_word.upper()}\\n"')
            continue
        if mnemonic in ('div', 'divu') and operands.startswith('zero,'):
            output.append(f'    ".word 0x{raw_word.upper()}\\n"')
            continue
        operands = re.sub(r'0x[0-9a-f]+', target_name, operands)
        operands = pattern.sub(lambda match: f'${REGISTERS[match.group(1)]}', operands)
        if mnemonic == 'beqzl':
            mnemonic = 'beql'
            operands = operands.replace(',', ',$0,', 1)
        elif mnemonic == 'bnezl':
            mnemonic = 'bnel'
            operands = operands.replace(',', ',$0,', 1)
        instruction = mnemonic + ((' ' + operands) if operands else '')
        output.append('    "' + instruction.replace('"', '\\"') + '\\n"')
    if end in labels:
        output.append(f'    "L_{end:08X}:\\n"')
    output.extend(['    ".end ' + args.name + '\\n.set at\\n.set reorder\\n");', ''])
    print('\n'.join(output))


if __name__ == '__main__':
    main()
