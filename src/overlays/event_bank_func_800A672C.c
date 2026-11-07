typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

#define QUIET(o) ((u32)((o)[31919] - 3) < 2)

typedef struct Ent {
    s8 type;
    u8 id;
    u8 pad2[6];
    s8 used;
    u8 pad9[3];
} Ent;

typedef struct Tm {
    u8 kind;
    u8 pad[59];
} Tm;

typedef struct Glob {
    u8 pad[32];
    Tm tm[8];
} Glob;

extern u8 *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(char *a, s32 b, s32 c, s32 d);

void func_800A672C(u8 *o)
{
    Ent *e;
    u32 i;
    s32 x;
    s32 k;
    s32 msg;
    s32 val;

    if (o[31919] < 2) {
        e = (Ent *)(D_800FC270 + 2576);
        for (i = 0; i < D_800FC270[2572]; i++) {
            if (e[i].used == 0) {
                break;
            }
        }
        if (i != D_800FC270[2572]) {
            if (e[i].type != 8) {
                x = ((Glob *)D_800FC270)->tm[e[i].type].kind;
            } else {
                x = 3;
            }
            if (x != 3) {
                k = 8;
                val = e[i].type;
            } else {
                k = 114;
                val = e[i].id;
            }
            msg = k + val;
            if (!QUIET(o)) {
                func_800C0110(D_800F3BC0, msg, 15360, 76800);
            }
        }
    }
}
