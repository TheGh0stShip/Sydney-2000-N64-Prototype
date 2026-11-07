typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u8 pad[104]; s32 vol; } Snd;
typedef struct { u8 pad[196]; s32 v; } Item;
typedef struct {
    u8 pad[204];
    Item *items[93];
    s32 i576;
    u8 pad2[4];
    u8 cur;
    u8 max;
    u8 pad3[6];
    s32 timer;
    u8 pad4[4];
    float rate;
} Obj;
extern Snd D_800F1AE0;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_800C99FC(Obj *o)
{
    u8 n;
    u8 i;
    n = (o->timer += 256) / 30.0f * 0.00390625f / o->rate;
    if (o->max < n) {
        n = o->max;
    }
    if (o->cur != n) {
        for (i = o->cur; i < n; i++) {
            o->items[i]->v = o->i576;
        }
        func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 272, 0, 1), scl(D_800F1AE0.vol, 32767));
        o->cur = n;
    }
}
