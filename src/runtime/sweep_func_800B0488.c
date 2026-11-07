typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 pad[20]; s32 flags; } Info;
typedef struct { u8 pad[104]; s32 vol; } Snd;
typedef struct Obj {
    u8 pad0[8];
    struct Obj *child;
    struct Obj *next;
    u8 pad1[160 - 16];
    f32 f160;
    u8 pad2[192 - 164];
    s32 flags192;
    u8 pad3[220 - 196];
    Info *info;
    u8 pad4[684 - 224];
    u8 col[772 - 684];
    f32 f772;
    s32 state;
    u8 pad5[788 - 780];
    u8 alpha;
    u8 pad6[796 - 789];
    u8 r;
    u8 g;
    u8 b;
    u8 c799;
    u8 c800;
    u8 c801;
    u8 pad7[2];
    s32 f804;
    s32 mode;
} Obj;
extern s32 D_800F26A8;
extern Snd D_800F1AE0;
s32 func_8001D4B8(Snd *s, s32 id, s32 a, s32 b);
void func_8001D640(Snd *s, s32 h, s32 v);
void func_800191E0(void *p, u32 c);
void func_800B08E4(Obj *o);
s32 func_800B0A0C(Obj *o);
void func_800B32D4(Obj *o, s32 a);
static inline s32 more(Obj *c)
{
    return c != 0;
}
static inline s32 vscale(s32 v, s32 k)
{
    return (v * k) >> 15;
}
void func_800B0488(Obj *o)
{
    s32 st = o->state;
    Obj *c;
    switch (st) {
    case 1: {
        f32 a = o->f772;
        if (a + 54.833332f < o->f160) {
            o->f160 = o->f160 - 54.833332f;
            if (o->info->flags & 0x10000) {
                func_800B08E4(o);
            }
        } else {
            o->f160 = a;
            if (D_800F26A8 == 0) {
                s32 h = func_8001D4B8(&D_800F1AE0, 194, 0, 1);
                func_8001D640(&D_800F1AE0, h, vscale(D_800F1AE0.vol, 32767));
                D_800F26A8 = st;
            }
            o->state = 2;
        }
        break;
    }
    case 2:
        if (o->info->flags & 0x10000) {
            func_800B08E4(o);
            break;
        }
        if ((u32)(o->mode - 1) < 2) {
            o->c799 = 61;
            o->c800 = 100;
            o->c801 = 192;
            o->f804 = 0;
            func_800191E0(o->col, o->b | (o->g << 8) | (o->r << 16) | 0xFF000000);
            o->mode = 3;
            o->alpha = 255;
            func_800B32D4(o, 255);
            c = o->child;
            if (c != 0) {
                while (more(c)) {
                    if (c->flags192 & 0x10000) {
                        func_800B32D4(c, o->alpha);
                    }
                    c = c->next;
                }
            }
        }
        if (o->mode == 3) {
            if (func_800B0A0C(o)) {
                o->mode = 4;
            }
            func_800191E0(o->col, o->b | (o->g << 8) | (o->r << 16) | 0xFF000000);
        }
        break;
    }
}
