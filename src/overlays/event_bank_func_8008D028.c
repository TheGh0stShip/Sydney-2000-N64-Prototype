typedef unsigned char u8;
typedef signed char s8;
typedef struct Ent { s8 kind; char pad[11]; } Ent;
typedef struct Kind { u8 type; char pad[59]; } Kind;
typedef struct G {
    char pad[0x20];
    Kind kinds[42];
    char pad9F8[0xA0C - 0x9F8];
    u8 count;
    char padA0D[3];
    Ent ents[1];
} G;
typedef struct Obj {
    char pad[0x59DC];
    int unk59DC;
    char pad59E0[0x8415 - 0x59E0];
    u8 idx;
} Obj;
extern G *D_800FC270;
extern void func_8007492C(Obj *, int);
extern float func_8007B04C(int);
extern void func_80074DAC(Obj *, float);
extern void func_80075050(Obj *);
void func_8008D028(Obj *o)
{
    int t;
    while (1) {
        s8 i = o->idx;
        if (!(i < D_800FC270->count)) break;
        i = D_800FC270->ents[i].kind;
        if (i != 8) {
            t = D_800FC270->kinds[i].type;
        } else {
            t = 3;
        }
        if (t == 3) {
            func_8007492C(o, 1);
            func_80074DAC(o, func_8007B04C(o->unk59DC));
            func_80075050(o);
        }
        o->idx++;
    }
    o->idx--;
}
