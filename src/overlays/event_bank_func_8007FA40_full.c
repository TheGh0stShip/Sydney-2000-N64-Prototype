typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad0[0xA00];
    s32 mode;
    s32 sub;
} EvState;

extern EvState *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);
extern void func_80077E24(u8 *);

void func_8007FA40(u8 *ctx)
{
    EvState *g = D_800FC270;
    s32 sub;
    s32 a, b, c;

    sub = g->sub;
    if (sub == 0) {
        return;
    }
    b = -1; a = b; c = b;
    if (ctx[0x8C9B] != 0 && ctx[0x8C99] == 0) {
        s32 m = g->mode;
        if (m == 5) {
            c = 0;
        } else if (m != 4) {
            if (m == 0) {
                c = 360;
            } else if (m == 1) {
                c = 362;
            } else if (m == 2) {
                c = 364;
            }
        } else {
            if (sub == 2) {
                a = 368; b = 294; c = 371;
            } else if (sub == 4) {
                a = 369; b = 294; c = 372;
            } else if (sub == 5) {
                a = 367; b = 294; c = 370;
            }
        }
    }
    if (a != -1 && (u8)(ctx[0x8C9D] - 3) >= 2) {
        func_800C0110(D_800F3BC0, a, 0, 0);
    }
    if (b != -1 && (u8)(ctx[0x8C9D] - 3) >= 2) {
        func_800C0110(D_800F3BC0, b, 0, 0);
    }
    if (c != -1 && (u8)(ctx[0x8C9D] - 3) >= 2) {
        func_800C0110(D_800F3BC0, c, 0, 0x12C00);
    }
    func_80077E24(ctx);
}
