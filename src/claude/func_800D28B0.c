typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char D_80089F28[];
extern char D_80086598[];
extern char D_8008A410[];
extern void func_800ADE10(char *self);

/* Constructor-style init (looks like g++ ctor output): base at +0, member at
 * +0xFC, 4-element array (stride 0xD4) at +0x210, then ctor body. Returns self.
 * The dead `q = 0` and the s32 `one` temporary reproduce the original CSE
 * behaviour (separate return pseudo / un-shared constant). */
char *func_800D28B0(char *self)
{
    char *m;
    char *p;
    char *q;
    s32 i;
    s32 one;

    q = 0;
    func_800ADE10(self);
    m = self + 0xFC;
    *(char **)(self + 0xB4) = D_80089F28;
    func_800ADE10(m);
    *(char **)(m + 0xB4) = D_80086598;
    *(s32 *)(self + 0xFC) = 0x3E;
    one = 1;
    *(u8 *)(m + 0xB0) = one;
    *(s16 *)(m + 0xD6) = -1;
    *(s16 *)(m + 0xD8) = -1;
    *(s16 *)(m + 0xD4) = 4;
    *(char **)(m + 0xB4) = D_8008A410;
    *(s32 *)(self + 0xFC) = 0xC;
    *(u8 *)(m + 0xB1) = 1;
    *(s32 *)(m + 0xE0) = 0;
    *(s32 *)(m + 0xDC) = 0;
    *(s32 *)(m + 0xE8) = 0;
    p = self + 0x210;
    i = 3;
    do {
        func_800ADE10(p);
        p += 0xD4;
    } while (--i != -1);
    q = self;
    *(s32 *)(q + 0xE4) = 0xEF;
    *(char **)(q + 0xE8) = q + 0x1E8;
    *(s32 *)(q + 0x0) = 0x47;
    *(u8 *)(q + 0xB1) = 1;
    *(s16 *)(q + 0xD4) = 0;
    *(s16 *)(q + 0xD6) = 0;
    *(s32 *)(q + 0xE0) = 0;
    *(s32 *)(q + 0x1F0) = 0;
    *(s32 *)(q + 0x1EC) = 0;
    *(s32 *)(q + 0x1E8) = 0;
    *(s32 *)(q + 0x1F8) = 0;
    *(s32 *)(q + 0x1FC) = 0;
    *(s32 *)(q + 0x20C) = 0;
    *(s32 *)(q + 0x208) = 0;
    *(s32 *)(q + 0x204) = 0;
    *(s32 *)(q + 0x200) = 0;
    *(s32 *)(q + 0xAC) = 5;
    return q;
}
