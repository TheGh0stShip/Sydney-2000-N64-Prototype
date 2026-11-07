typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern u8 *D_800FC270;
extern char D_800F3BC0[];
extern s8 func_8009B73C(s32 a);
extern void func_800C0110(char *a, s32 b, s32 c, s32 d);

typedef struct Ent {
    u8 pad0;
    u8 id;
    u8 pad2[6];
    s8 used;
    u8 pad9[3];
} Ent;

#define QUIET(o) ((u32)((o)[23423] - 3) < 2)

void func_800B577C(u8 *o)
{
    s8 r = func_8009B73C(0);
    u8 *g = D_800FC270;
    Ent *e;
    u32 i;

    switch (*(s32 *)(g + 2564)) {
    case 2:
        if (!QUIET(o)) {
            func_800C0110(D_800F3BC0, 478, 7680, 23040);
        }
        break;
    case 3:
        if (!QUIET(o)) {
            func_800C0110(D_800F3BC0, 477, 7680, 23040);
        }
        if (r >= 7) {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 173, 23040, 76800);
            }
        } else {
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 180, 23040, 76800);
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
            s32 v = e[i].id + 215;
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, v, 7680, 23040);
            }
        }
        switch (r) {
        case 0:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 178, 23040, 76800);
            }
            break;
        case 1:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 176, 23040, 76800);
            }
            break;
        case 2:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 177, 23040, 76800);
            }
            break;
        case 3:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 175, 23040, 76800);
            }
            break;
        default:
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, 170, 23040, 76800);
            }
            break;
        }
        break;
    }
}
