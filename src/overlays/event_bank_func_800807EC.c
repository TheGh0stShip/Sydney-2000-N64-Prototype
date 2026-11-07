typedef unsigned char u8;
typedef struct G { char pad[0xA00]; int kind; int sub; } G;
typedef struct Obj {
    char pad[0x8C9D];
    u8 unk8C9D;
    char pad8C9E[0x8CCC - 0x8C9E];
    float level;
    char pad8CD0[4];
    int unk8CD4;
} Obj;
extern G *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *, int, int, int);
static inline void play(Obj *o, int id)
{
    if (o->unk8C9D != 3 && o->unk8C9D != 4) {
        func_800C0110(D_800F3BC0, id, 30720, 122880);
    }
}
void func_800807EC(Obj *o)
{
    int id = 0;
    if (D_800FC270->kind == 4) {
        if (D_800FC270->sub == 4) {
            id = 2;
        } else if (D_800FC270->sub == 5) {
            id = 1;
        }
    }
    if (o->unk8CD4 != 190) {
        o->level -= 10.0f;
        if (o->level < 0.0f) {
            o->level = 0.0f;
        }
    }
    if (0.0f <= o->level && o->level < 10.0f) {
        play(o, id + 46);
    } else if (10.0f <= o->level && o->level < 20.0f) {
        play(o, id | 40);
    } else if (20.0f <= o->level && o->level < 30.0f) {
        play(o, id + 37);
    } else if (30.0f <= o->level && o->level < 40.0f) {
        play(o, id + 43);
    } else {
        play(o, id + 49);
    }
}
