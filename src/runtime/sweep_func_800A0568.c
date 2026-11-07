typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec pos; } Xf;
typedef struct { char pad[12]; int *pv; Vec **pos; } Hdr;
typedef struct {
    char pad0[20]; Xf xf;
    char pad1[196 - 96]; int res;
    char pad2[212 - 200]; int busy; Vec v216; Xf *xp;
} Obj;
extern char D_80084CC0[];
extern void func_80013E7C(char *, Hdr **, int);
extern void func_800ADC54(Obj *, int);
extern void func_800AD890(Obj *, int);
extern void func_800AD2A8(Xf *, Vec *, Vec *, int);
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
void func_800A0568(Obj *o)
{
    Hdr *h;
    Xf *x;
    if (o->res == 0) {
        func_80013E7C(D_80084CC0, &h, 0);
        x = &o->xf;
        o->res = *h->pv;
        x->m[0] = 0.0f; x->m[1] = 0.0f; x->m[2] = -1.0f;
        x->m[4] = -1.0f; x->m[5] = 0.0f; x->m[6] = 0.0f;
        x->m[8] = 0.0f; x->m[9] = 1.0f; x->m[10] = 0.0f;
        func_800ADC54(o, 1);
        o->xf.pos.x = 489.36874f;
        o->xf.pos.y = -1.31068f;
        o->xf.pos.z = 1856.5767f;
        func_800AD890(o, 1);
        o->xp = x;
        vcpy(*h->pos, &o->v216);
        func_800AD2A8(x, *h->pos, &o->xf.pos, 1);
    }
    o->busy = 0;
}
