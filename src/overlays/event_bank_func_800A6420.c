typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_800FC270;
extern char D_800F3BC0[];
extern s8 func_8009B73C(u8 **a);
extern void func_800C0110(char *a, s32 b, s32 c, s32 d);

typedef struct Ent {
    u8 pad0;
    u8 id;
    u8 pad2[6];
    s8 used;
    u8 pad9[3];
} Ent;

#define QUIET(o) ((u32)((o)[31919] - 3) < 2)

void func_800A6420(u8 *o)
{
    u8 *pp;
    s8 r = func_8009B73C(&pp);
    u8 *g = D_800FC270;
    Ent *e;
    u32 i;

    switch (*(s32 *)(g + 2564)) {
    case 1:
        if (!QUIET(o)) {
            func_800C0110(D_800F3BC0, 303, 7680, 23040);
        }
        if (r >= 13 && *(f32 *)(pp + 4) < *(f32 *)(D_800FC270 + 3344)) {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 190, 23040, 76800);
            }
        } else {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 197, 23040, 76800);
            }
        }
        break;
    case 4:
        if (!QUIET(o)) {
            func_800C0110(D_800F3BC0, 305, 7680, 23040);
        }
        if (r >= 9) {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 191, 23040, 76800);
            }
        } else {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 198, 23040, 76800);
            }
        }
        break;
    case 5:
        e = (Ent *)(g + 2576);
        for (i = 0; i < D_800FC270[2572]; i++) {
            if (e[i].used == 0) {
                break;
            }
        }
        if (i != D_800FC270[2572]) {
            s32 v = e[i].id + 232;
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, v, 7680, 23040);
            }
        }
        switch (r) {
        case 0:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 195, 23040, 76800);
            }
            break;
        case 1:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 193, 23040, 76800);
            }
            break;
        case 2:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 194, 23040, 76800);
            }
            break;
        case 3:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 192, 23040, 76800);
            }
            break;
        default:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 187, 23040, 76800);
            }
            break;
        }
        break;
    }
}
