typedef int s32;
typedef unsigned char u8;
typedef struct { u8 pad[104]; s32 vol; } Snd;
extern Snd D_800F1AE0;
extern u8 *D_800FC270;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_8001D5D8(Snd *, s32, s32, s32, s32, s32);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_80076A50(u8 *o)
{
    s32 h;
    s32 x;
    if (*(s32 *)(D_800FC270 + 2560) != 6 && *(s32 *)(D_800FC270 + 2564) != 0) {
        if (*(s32 *)(o + 25344) == -1) {
            h = func_8001D4B8(&D_800F1AE0, 111, 0, -1);
            func_8001D640(&D_800F1AE0, h, 0);
            func_8001D5D8(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767), 60, 0, 0);
            *(s32 *)(o + 25344) = h;
        }
        x = *(s32 *)(o + 25336);
        func_8001D5D8(&D_800F1AE0, x, 0, 60, 1, 0);
    }
}
