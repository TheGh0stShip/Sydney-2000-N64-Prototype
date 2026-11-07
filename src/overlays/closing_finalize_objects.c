typedef unsigned char u8;
extern void func_800AC3A4(void *, int); extern void func_8007F1A4(void *, int); extern void func_800A9C2C(void *, int);
extern void func_800AF064(void *, int); extern void func_800ADE84(void *, int); extern void func_800AE4D8(void *, int); extern void func_800A86AC(void *, int);
extern char D_8008C140[];
void func_8007268C(u8 *o, int mode) {
    u8 *sub = o + 0x1FD8; u8 *b = o + 0x21DC;
    if (b != 0) { u8 *p = b + 0x180; while (b != p) p -= 16; }
    *(void **)(sub + 0xB4) = D_8008C140; func_800AC3A4(sub, 2);
    func_8007F1A4(o + 0xAA0, 2); func_800A9C2C(o + 0x9AC, 2); func_800AF064(o + 0x99C, 2); func_800AF064(o + 0x98C, 2);
    func_800ADE84(o + 0x86C, 2); func_800AC3A4(o + 0x7AC, 2); func_800AE4D8(o + 0x250, 2); func_800A86AC(o + 0xE8, 2);
    func_800AC3A4(o, mode);
}
