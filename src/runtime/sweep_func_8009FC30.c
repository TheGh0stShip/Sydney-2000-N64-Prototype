typedef struct { float x, y, z; } Vec;
typedef struct { char pad0[12]; Vec pos; Vec vel; Vec acc; int flags; } Rec;
typedef struct { char pad0[184]; int w; int h; char pad1[196 - 192]; Rec *recs; } Obj;
static inline void vscl(Vec *a, float k, Vec *r) { r->x = a->x * k; r->y = a->y * k; r->z = a->z * k; }
static inline void vadd(Vec *a, Vec *b, Vec *r) { r->x = a->x + b->x; r->y = a->y + b->y; r->z = a->z + b->z; }
void func_8009FC30(Obj *o, int n)
{
    Vec t;
    int i;
    float k = (float)n / 30.0f * 0.00390625f;
    i = 0;
    while (1) {
        if (!(i < o->w * o->h)) break;
        if (!(o->recs[i].flags & 1)) {
            vscl(&o->recs[i].pos, k, &o->recs[i].vel);
            vscl(&o->recs[i].acc, k, &t);
            vadd(&o->recs[i].pos, &t, &o->recs[i].pos);
        }
        i++;
    }
}
