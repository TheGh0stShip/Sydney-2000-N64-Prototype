typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
    char padA08[0xD53 - 0xA08];
    u8 level;
} Game;

extern Game *D_800FC270;
extern u8 D_800F3BC0[];
extern f32 D_80076F18[][7];
extern void func_800C0110(void *, s32, s32, s32);

void func_80075C6C(u8 *obj, f32 v)
{
    Game *g;
    f32 base;
    f32 lo;
    f32 mid;
    s32 snd;

    if (*(s32 *)(*(u8 **)(obj + 12136) + 744) != 0) {
        g = D_800FC270;
        base = D_80076F18[g->level][g->mode];
        lo = base * 0.8f;
        mid = base * 0.93f;
        if (v < lo) {
            if (g->sub != 0) {
                func_800C0110(D_800F3BC0, 1, 0, 0);
            }
        } else if (v < mid) {
            if (g->sub != 0) {
                func_800C0110(D_800F3BC0, 0, 0, 0);
            }
        } else if (v < base) {
            if (g->sub != 0) {
                func_800C0110(D_800F3BC0, 3, 0, 0);
            }
        } else {
            if (g->sub != 0) {
                func_800C0110(D_800F3BC0, 28, 0, 0);
            }
        }
    } else {
        if (D_800FC270->sub != 0) {
            func_800C0110(D_800F3BC0, 2, 0, 0);
        }
    }
}
