typedef int s32;
typedef unsigned char u8;
typedef struct { u8 pad[104]; s32 vol; } Snd;
extern Snd D_800F1AE0;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_8001D5D8(Snd *, s32, s32, s32, s32, s32);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_800759A0(u8 *o)
{
    s32 h;
    s32 x;
    x = *(s32 *)(o + 25332);
    *(s32 *)(o + 25336) = -1;
    *(s32 *)(o + 25340) = -1;
    *(s32 *)(o + 25344) = -1;
    func_8001D5D8(&D_800F1AE0, x, 0, 15, 1, 0);
    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 213, 0, 1), scl(D_800F1AE0.vol, 32767));
    h = func_8001D4B8(&D_800F1AE0, 109, 0, -1);
    func_8001D640(&D_800F1AE0, h, 0);
    func_8001D5D8(&D_800F1AE0, h, scl(D_800F1AE0.vol, 26213), 45, 0, 0);
    *(s32 *)(o + 25336) = h;
}
