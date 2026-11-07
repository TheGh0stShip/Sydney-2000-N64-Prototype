typedef int s32;
typedef unsigned char u8;
extern void *D_80083C80[];
extern char D_80081AE8[];
extern char D_80065B00[];
extern s32 func_800BA2D0(void *);
extern void *func_800140A0(char *, s32, s32);
extern void func_800B7130(u8 *, void *, s32, s32, s32);
extern void func_800148F8(u8 *, char *);
extern void func_800AD890(u8 *, s32);
extern void func_800ADC54(u8 *, s32);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800ADC38(u8 *);
extern void func_80082764(u8 *, s32);
void func_8008382C(u8 *o, s32 i)
{
    s32 r;
    void *m;
    u8 *p;
    *(s32 *)(o + 4960) = 0;
    *(s32 *)(o + 13524) |= 0x20;
    r = func_800BA2D0(D_80083C80[i]);
    *(s32 *)(o + 4956) = r;
    if (r == 0) return;
    m = func_800140A0(D_80081AE8, 0, 0);
    if (m == 0) return;
    p = o + 4552;
    func_800B7130(p, m, *(s32 *)(o + 4956), 0, 0);
    func_800148F8(p, D_80065B00);
    func_800AD890(p, 1);
    *(float *)(*(u8 **)(*(u8 **)(p + 208) + 8) + 40) = 32.767f;
    func_800ADC54(p, 1);
    func_800AC37C(p, o);
    func_800ADC38(p);
    *(s32 *)(p + 192) = (*(s32 *)(p + 192) & ~0x600) | 0x2000000;
    func_80082764(o, i);
}
