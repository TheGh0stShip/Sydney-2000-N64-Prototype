typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
} Game;

extern Game *D_800FC270;
extern u32 D_800F2714;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);

#define STATE(o) (*(s32 *)((o) + 21568))

void func_80075F70(u8 *o)
{
    Game *g = D_800FC270;
    s32 a;
    s32 b;

    if (g->mode == 4) {
        if (g->sub == 5) {
            a = 356;
        } else if (g->sub != g->mode) {
            a = 357;
        } else {
            a = 358;
        }
        b = -1;
    } else {
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        if ((D_800F2714 >> 29) != 0) {
            a = 162;
        } else {
            a = 161;
        }
        b = -1;
    }
    if (a != -1) {
        if (D_800FC270->sub != 0 && STATE(o) == 1) {
            func_800C0110(D_800F3BC0, a, 3072, 0);
        }
    }
    if (b != -1) {
        if (D_800FC270->sub != 0 && STATE(o) == 1) {
            func_800C0110(D_800F3BC0, b, 18432, 0);
        }
    }
}
