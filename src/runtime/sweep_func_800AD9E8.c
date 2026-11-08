typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec pos; } Xf;
typedef struct { Vec a; Vec cur; Vec prev; u8 kind; char pad; short id; Vec b; Vec c; char pad2[72 - 64]; } Col;
typedef struct { u8 n; u8 b1; u16 s[3]; Col *c[3]; int v20; int v24; } Hdr;
typedef struct { char pad0[20]; Xf xf; char pad1[208 - 96]; Hdr *h; } Obj;
extern void func_800AD2A8(Xf *, void *, Vec *, int);
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
void func_800AD9E8(Obj *o)
{
    u8 i;
    u16 j;
    Col *c;
    Vec *arg;
    if (o->h == 0) return;
    i = 0;
    while (1) {
        if (!(i < o->h->n)) break;
        j = 0;
        while (1) {
            if (!(j < o->h->s[i])) break;
            c = &o->h->c[i][j];
            vcpy(&c->cur, &c->prev);
            arg = &c->cur;
            if (c->a.x != 0.0f || c->a.y != 0.0f || c->a.z != 0.0f) {
                func_800AD2A8(&o->xf, c, arg, 1);
            } else {
                vcpy(&o->xf.pos, &c->cur);
            }
            if (c->kind == 4) func_800AD2A8(&o->xf, &c->c, &c->b, 0);
            j++;
        }
        i++;
    }
}
