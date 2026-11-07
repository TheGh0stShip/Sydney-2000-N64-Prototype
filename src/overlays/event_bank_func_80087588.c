typedef unsigned char u8;
typedef struct Glob { char pad[2560]; int phase; int sound; } Glob;
typedef struct Rec { char pad[34]; short state; } Rec;
typedef struct Obj {
    char pad[1116];
    char unk45C[1551 - 1116];
    u8 unk60F;
    char pad610[1557 - 1552];
    u8 state;
    char pad616[21232 - 1558];
    Rec recs[8];
    char pad2[21568 - 21232 - 8 * 36];
    int mode;
    char pad5444[21615 - 21572];
    u8 sel;
    char pad5470[21623 - 21616];
    u8 mask;
} Obj;
extern Glob *D_800FC270;
extern u8 D_80077730;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
extern void func_80075688(Obj *);
extern void func_800A9BE8(void *, int);
#define PLAY(o, id) \
    if ((id) != -1 && D_800FC270->sound != 0 && (o)->mode == 1) func_800C0110(D_800F3BC0, (id), 0, 0)
void func_800761B8(Obj *o, u8 bit)
{
    if (o->mask == D_80077730) {
        o->sel = bit;
        if (D_800FC270->phase != 6) {
            if (o->state == 5) {
                func_80075688(o);
                o->unk60F = 19;
            } else if (o->recs[o->sel].state != 1) {
                PLAY(o, o->sel + 579);
            }
        }
    }
    o->mask &= ~(1 << bit);
    if (o->mask == 0 && o->state == 5) {
        func_800A9BE8(o->unk45C, 20);
    }
}
