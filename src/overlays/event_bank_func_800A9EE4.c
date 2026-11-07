typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad[0x68];
    s32 vol;
} Snd;

typedef struct Arg { u8 pad[16]; s32 on; } Arg;

extern Snd D_800F1AE0;
extern s32 D_800F2728;

extern void func_80075264(u8 *p, s32 a);
extern s32 func_8001D4B8(Snd *s, s32 a, s32 b, s32 c);
extern void func_8001D640(Snd *s, s32 h, s32 v);
extern void func_8001D5D8(Snd *s, s32 h, s32 v, s32 a, s32 b, s32 c);
extern void func_800A6308(u8 *p);
extern void func_800771D4(u8 *p);
extern void func_80077120(u8 *p);

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

#define W(o) (*(s32 *)(p + (o)))
#define Q(o) (*(u8 *)(p + 0x8000 + (o)))
#define QW(o) (*(s32 *)(p + 0x8000 + (o)))

void func_800A9EE4(u8 *p, Arg *a)
{
    s32 h;

    if (Q(286) != 5) {
        if (a->on != 0) {
            func_80075264(p, W(13772));
            if ((u8)(Q(286) - 2) >= 3) {
                h = func_8001D4B8(&D_800F1AE0, 215, 0, 0);
                func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
            }
            if (Q(286) != 4) {
                h = func_8001D4B8(&D_800F1AE0, 111, 0, -1);
                func_8001D640(&D_800F1AE0, h, 0);
                func_8001D5D8(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767), 0x9600, 0, 0);
                QW(344) = h;
                func_800A6308(p + 6296);
            }
        } else {
            func_80075264(p, 0);
        }
    }
    if (a->on != 0) {
        func_800771D4(p);
    } else {
        func_80077120(p);
    }
    QW(300) = 7680;
    Q(285) = 11;
    D_800F2728 = 0;
}
