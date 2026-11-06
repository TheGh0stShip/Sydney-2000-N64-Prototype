typedef struct {
    char pad0[3];
    unsigned char streak;
    char pad4[0x18];
    int target;
} Entry;

typedef struct {
    signed char kind;
    char pad[11];
} Lane;

typedef struct {
    char pad0[0x20];
    unsigned char type;
    char pad21[0x3C - 0x21];
} Team;

typedef struct {
    Team teams[1];
    char pad[0xA0C - 0x3C];
    unsigned char lanes_n;
    char pad2[3];
    Lane lanes[1];
} Global;

extern Global *D_800FC270;
extern unsigned int D_800F2C14;
extern void func_80075264(char *obj, unsigned int v);
extern void func_80075AEC(char *obj);

#define CUR (*(signed char *)(obj + 0x8000 + 0x11C))
#define E ((Entry *)((CUR << 5) + *(int *)(obj + 0x8000 + 0x13C)))

void func_80075100(char *obj)
{
    unsigned int r;
    int type;
    int kind;
    unsigned int n;

    CUR = 0;
    while (1) {
        if (CUR >= D_800FC270->lanes_n) {
            break;
        }
        kind = D_800FC270->lanes[CUR].kind;
        if (kind != 8) {
            type = D_800FC270->teams[kind].type;
        } else {
            type = 3;
        }
        if (type != 1 && E->streak < 3) {
            D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
            n = 3;
            r = ((D_800F2C14 >> 15) * n) >> 16;
            func_80075264(obj, E->target - r * 5);
            func_80075AEC(obj);
        }
        CUR++;
    }
    *(signed char *)(obj + 0x8000 + 0x11C) -= 1;
}
