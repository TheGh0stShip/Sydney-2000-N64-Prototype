/* Event-bank sound cue dispatcher: selects a cue id by event index and plays it. */
extern char eventSoundBank[];
extern void *D_80070C88[];
extern char eventCueErrorFormat[];
extern char eventCueErrorFile[];
extern void func_800C0110(void *bank, int cue, int volume, int pitch);
extern void func_800AAA60(char *fmt, int line, char *file);

void func_80073278(int unused, unsigned int index)
{
    static void *const unused_tbl[12] = {
        &&L0, &&L1, &&L2, &&L3, &&L4, &&L5, &&L6, &&L7, &&L8, &&L9, &&L10, &&L11
    };

    if (index >= 12)
        goto invalid;
    goto *D_80070C88[index];
L0: func_800C0110(eventSoundBank, 74, 0x1E00, 0x12C00); return;
L1: func_800C0110(eventSoundBank, 75, 0x1E00, 0x12C00); return;
L2: func_800C0110(eventSoundBank, 80, 0x1E00, 0x12C00); return;
L3: func_800C0110(eventSoundBank, 78, 0x1E00, 0x12C00); return;
L4: func_800C0110(eventSoundBank, 85, 0x1E00, 0x12C00); return;
L5: func_800C0110(eventSoundBank, 79, 0x3C00, 0x12C00); return;
L6: func_800C0110(eventSoundBank, 82, 0x1E00, 0x12C00); return;
L7: func_800C0110(eventSoundBank, 83, 0x1E00, 0x12C00); return;
L8: func_800C0110(eventSoundBank, 77, 0x1E00, 0x12C00); return;
L9: func_800C0110(eventSoundBank, 84, 0x1E00, 0x12C00); return;
L10: func_800C0110(eventSoundBank, 76, 0x1E00, 0x12C00); return;
L11: func_800C0110(eventSoundBank, 81, 0x1E00, 0x12C00); return;
invalid:
    func_800AAA60(eventCueErrorFormat, 2064, eventCueErrorFile);
}
