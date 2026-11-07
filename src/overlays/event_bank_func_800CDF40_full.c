typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    u16 pad0;
    u16 t;
    u8 pad4[36];
} Key;

typedef struct {
    u8 pad[28];
    Key *keys;
} Anim;

void func_80071820(u8 *p)
{
    u8 *s = p + 4552;
    f32 f;

    f = 1.0f - (f32)(u16)(*(u16 *)(s + 252) - (*(Anim **)(s + 244))->keys[*(s32 *)(s + 264)].t) / (f32)*(u16 *)(p + 17602);
    f = (f + f + 1.0f) * 7680.0f;
    p[17584] = 0;
    p[17587] = 1;
    *(s32 *)(p + 17596) = f;
}
