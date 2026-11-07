typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 pad[0x68];
    s32 vol;
} Snd;

extern Snd D_800F1AE0;

extern void func_80071CEC(u8 *p);
extern s32 func_800B9BD4(u8 *o, s32 x, float *a, float *b, float *c, s32 z);
extern void func_800B9964(u8 *o, float *a, float *b, float *c);
extern void func_80083624(u8 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_800C9EF8(u8 *p, u8 v);
extern s32 func_8001D4B8(Snd *s, s32 a, s32 b, s32 c);
extern void func_8001D640(Snd *s, s32 h, s32 v);

typedef struct {
    u8 pad[0xC0];
    s32 flags;
    u8 pad2[212 - 0xC4];
} Ent;

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

void func_800C297C(u8 *p, s32 x)
{
    float a[4];
    float c[4];
    float b[2];

    W(0xF0C) -= 0x100;
    if (W(0xF0C) <= 0) {
        W(0x42EC) = 2;
    }
    if (W(0x4BC8) == 1) {
        func_80071CEC(p);
    }
    if (func_800B9BD4(p + 0x11C8, x, a, b, c, 0) != 0) {
        if (++B(0x4BAF) == 2) {
            if (B(0x4BAE) == B(0x4BAD)) {
                W(0x42EC) = 5;
                B(0x4BAF) = 0;
                W(0x4BBC) = 1;
                W(0x4BC4) = 1;
            } else {
                W(0x42EC) = 6;
                B(0x4BAF) = 0;
                W(0x4BC4) = 0;
            }
            W(0x4BD4) = 0;
            W(0x4BCC) = 0;
            W(0x4BD0) = 0;
        }
        if (B(0x4BAF) == 1 && B(0x4BAE) == B(0x4BAD)) {
            ((Ent *)(p + 0x4304))[B(0x4BAD)].flags |= 4;
            ((Ent *)(p + 0x4664))[B(0x4BAD)].flags &= ~4;
        }
        if (B(0x4BAE) == B(0x4BAD)) {
            if (B(0x4BAF) == 1) {
                W(0x4B74)++;
                func_80083624(p, 58, W(0x4B74), 0, 0, 0);
                func_800C9EF8(p + 0x2598, B(0x4B77));
                W(0x4BC8) = 0;
            }
        } else if (B(0x4BAF) == 1) {
            s32 h = func_8001D4B8(&D_800F1AE0, 193, 0, 1);
            func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
            W(0x4BC8) = 1;
        }
    }
    func_800B9964(p + 0x11C8, a, b, c);
}
