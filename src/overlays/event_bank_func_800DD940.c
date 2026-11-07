typedef int s32;
typedef unsigned char u8;
typedef struct { u8 pad[104]; s32 vol; } Snd;
extern Snd D_800F1AE0;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_8001D5D8(Snd *, s32, s32, s32, s32, s32);
extern void func_80099D70(u8 *, int, float);
extern void func_8009B9EC(int, int);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_80071F50(u8 *o)
{
    s32 h;
    s32 x;
    if ((*(s32 *)(o + 25284) -= 256) <= 0) {
        if (!o[1557]) {
            func_80099D70(o + 20560, 1, 0.0f);
        }
        x = *(s32 *)(o + 25328);
        *(s32 *)(o + 25284) = 0x9600;
        o[1551] = 5;
        func_8001D5D8(&D_800F1AE0, x, 0, 270, 1, 0);
        h = func_8001D4B8(&D_800F1AE0, 96, 0, -1);
        func_8001D640(&D_800F1AE0, h, 0);
        func_8001D5D8(&D_800F1AE0, h, scl(D_800F1AE0.vol, 6553), 120, 0, 0);
        *(s32 *)(o + 25332) = h;
    }
    func_8009B9EC(23040, 0);
}
