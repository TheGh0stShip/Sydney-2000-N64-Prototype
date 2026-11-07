typedef struct { float x, y, z; } Vec;
typedef struct { char pad[64]; Vec pos; } Sub;
typedef struct { char pad[20]; Sub sub; } Obj;
typedef struct { char pad0[12]; Vec v; char pad1[28 - 24]; char a[12]; char b[12]; char c[4]; } Rec;
extern Obj *D_801005A8[];
extern Rec D_800F10B8[];
extern void func_800AD434(void *, float, int);
extern void func_800B9BD4(Obj *, int, void *, void *, void *, int);
static inline void setpos(Sub *s, float x, float y, float z) { s->pos.x = x; s->pos.y = y; s->pos.z = z; }
void func_8008F59C(void)
{
    int i = 0;
    while (1) {
        if (!(i < 2)) break;
        func_800AD434(&D_801005A8[i]->sub, 0.02f, 3);
        func_800B9BD4(D_801005A8[i], 1, D_800F10B8[i].a, D_800F10B8[i].c, D_800F10B8[i].b, 0);
        setpos(&D_801005A8[i]->sub, D_800F10B8[i].v.x * 32.766998f, D_800F10B8[i].v.y * 32.766998f, D_800F10B8[i].v.z * 32.766998f);
        i++;
    }
}
