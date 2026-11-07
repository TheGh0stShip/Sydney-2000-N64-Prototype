typedef unsigned char u8;
typedef signed char s8;
typedef struct Slot { s8 type; u8 b1; short unk2; char pad4[8]; } Slot;
typedef struct Ent { char pad[32]; u8 kind; char pad21[60 - 33]; } Ent;
typedef struct Glob { Ent ents[1]; } Glob;
typedef struct Obj {
    char pad[1550];
    u8 index;
    char pad60F[1555 - 1551];
    u8 stride;
    char pad614[25383 - 1556];
    u8 mode;
} Obj;
extern Glob *D_800FC270;
extern void func_8009A828(void *, int, int);
extern float func_800745B0(Obj *, void *, int, float, int);
extern void func_80074758(Obj *, int, float);
void func_8007714C(Obj *o)
{
    char buf[24];
    Slot *p = (Slot *)((char *)D_800FC270 + 2576) + o->index * o->stride;
    u8 i = 0;
    u8 k;
    float f;
    while (1) {
        u8 t;
        if (!(i < o->stride)) break;
        t = p->type;
        if (p->type != 8) {
            k = D_800FC270->ents[p->type].kind;
        } else {
            k = 3;
        }
        if (k != 1) {
            func_8009A828(buf, p->b1, (s8)t);
            f = func_800745B0(o, buf, 10, 10.0f, 10);
        } else {
            f = -1.0f;
        }
        func_80074758(o, i, f);
        p++;
        i++;
    }
    o->mode = 2;
}
