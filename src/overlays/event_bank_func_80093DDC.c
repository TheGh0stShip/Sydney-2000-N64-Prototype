typedef unsigned char u8;
typedef signed char s8;
typedef struct Slot { s8 type; char pad[11]; } Slot;
typedef struct Ent { char pad[32]; u8 kind; char pad21[60 - 33]; } Ent;
typedef struct Glob { Ent ents[42]; char padA08[2572 - 42 * 60]; u8 count; char padA0D[3]; Slot slots[1]; } Glob;
typedef struct E { char pad[4]; u8 b4; char pad5[16 - 5]; int w10; char pad14[28 - 20]; } E;
typedef struct Obj {
    char pad[30120];
    s8 idx;
    char pad75A9[30204 - 30121];
    E *ents;
} Obj;
extern Glob *D_800FC270;
extern unsigned int D_800F2C14;
extern void func_80074C84(Obj *, int, int);
extern void func_8007620C(Obj *);
static __inline__ unsigned int rnd(unsigned int *p, unsigned int n)
{
    *p = (*p * 16807) & 0x7FFFFFFF;
    return ((*p >> 15) * n) >> 16;
}

void func_80074B2C(Obj *o)
{
    o->idx = 0;
    while (1) {
        u8 k;
        if (!(o->idx < D_800FC270->count)) break;
        if (D_800FC270->slots[o->idx].type != 8) {
            k = D_800FC270->ents[D_800FC270->slots[o->idx].type].kind;
        } else {
            k = 3;
        }
        if (k != 1) {
            if (o->ents[o->idx].b4 < 3) {
                unsigned int r;
                r = rnd(&D_800F2C14, 3);
                func_80074C84(o, o->ents[o->idx].w10 - r * 3, r);
                func_8007620C(o);
            }
        }
        o->idx++;
    }
    o->idx--;
}
