typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Slot { s32 a; s32 b; } Slot;
typedef struct Obj { u8 pad[744]; Slot s[8]; } Obj;
typedef struct Mv { u8 pad[16]; u32 mask; u8 pad2[16]; } Mv;

typedef u8 DS;
extern DS D_800F26E0[];
extern s32 D_800F2744;

extern void func_800AAB54(u8 *p, s32 a, u8 *b);
extern void func_800AAA70(u8 *p, s32 a, u8 *b);
extern void func_800AB2A4(DS *a, s32 b, s32 c, s32 d, s32 e, s32 f);

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define SL (((Obj *)p)->s[B(1044)])
#define CUR ((u8 *)W(1080) + B(1044) * 36)

u32 func_800EB1DC(u8 *p, u32 k, u8 *buf)
{
    u8 *q;
    s32 c;
    u32 r;

    q = *(u8 **)(p + 4);
    if (W(1200) > 0) {
        return 0;
    }
    {
        c = 0;
        if (B(426) != 1) {
            c = q[0x8000 + 3229] != 5;
        }
        if (c) {
            if (W(172) == 23) {
                func_800AAB54(p, 16, buf);
                func_800AAA70(p, 16, buf + 256);
                r = 1;
            } else if (SL.a < 0) {
                func_800AAB54(p, ((u16 *)&SL.b)[1], buf);
                func_800AAA70(p, *(u16 *)(p + (B(1044) << 3) + 750), buf + 256);
                if (SL.b == 1) {
                    s32 t = W(4);

                    func_800AB2A4(D_800F26E0, D_800F2744, 13, t, 0, 0);
                }
                r = 1;
            } else {
                r = 0;
            }
        } else if (W(172) == 23) {
            r = k & 16;
        } else {
            if (k != 0) {
                if (!(k & *(u32 *)(CUR + 16))) {
                    W(1200) = 1536;
                }
            }
            r = k & *(u32 *)(CUR + 16);
        }
    }
    return r;
}
