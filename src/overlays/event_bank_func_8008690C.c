typedef unsigned char u8;
typedef struct Glob { char pad[2564]; int sound; } Glob;
typedef struct Ent { char pad[733]; u8 kind; } Ent;
typedef struct Rec { int x; int y; char pad8[34 - 8]; short state; } Rec;
typedef struct Obj {
    char pad[1548];
    u8 cur;
    char pad60D[16672 - 1549];
    Ent *ents[64];
    char pad4220[21232 - 16672 - 64 * 4];
    Rec recs[8];
    char pad2[21568 - 21232 - 8 * 36];
    int mode;
} Obj;
extern Glob *D_800FC270;
extern unsigned int D_800F2714;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
#define PLAY(o, id) \
    if ((id) != -1 && D_800FC270->sound != 0 && (o)->mode == 1) func_800C0110(D_800F3BC0, (id), 0, 0)
void func_8007553C(Obj *o)
{
    int k = o->ents[o->cur]->kind;

    int add;
    int s;
    if (o->recs[k].state != 1) {
        if (o->recs[k].x < 13825 && o->recs[k].y < 2305) {
            add = 153;
            s = 202;
        } else {
            add = 145;
            s = 201;
        }
        PLAY(o, k + add);
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        if ((D_800F2714 >> 28) < 5) {
            PLAY(o, s);
        }
    }
}
