typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
} Game;

extern Game *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_8009B80C(void *, s32, s32, s32);
extern void func_800C0110(void *, s32, s32, s32);

#define LVL(o) ((o)[1550])
#define STATE(o) (*(s32 *)((o) + 25320))

void func_80075A94(u8 *o)
{
    s32 a;
    s32 b;
    s32 mode;
    s32 sub;

    func_8009B80C(o + 12884, 1, (s8)LVL(o), 2);
    if (o[1557] == 4) {
        return;
    }
    a = -1;
    b = -1;
    mode = D_800FC270->mode;
    if (mode == 5) {
        if (LVL(o) == 0) {
            a = 48;
        }
    } else {
        sub = D_800FC270->sub;
        if (sub == 1) {
            if (mode == 0) {
                a = 331;
            } else if (mode == sub) {
                a = 333;
            } else if (mode == 2) {
                a = 335;
            }
        } else if (sub == 2) {
            if (LVL(o) == 0) {
                a = 338;
            }
            b = LVL(o) + 342;
        } else if (sub == 4) {
            a = LVL(o) + 339;
            b = LVL(o) + 346;
        } else if (sub == 5) {
            a = 337;
            b = 341;
        }
    }
    if (a != -1) {
        if (D_800FC270->sub != 0 && STATE(o) == 1) {
            func_800C0110(D_800F3BC0, a, 0, 0);
        }
        if (D_800FC270->mode == 4 && D_800FC270->sub != 0 && STATE(o) == 1) {
            func_800C0110(D_800F3BC0, 239, 0, 0);
        }
    }
    if (b != -1 && D_800FC270->sub != 0 && STATE(o) == 1) {
        func_800C0110(D_800F3BC0, b, 0, 0);
    }
}
