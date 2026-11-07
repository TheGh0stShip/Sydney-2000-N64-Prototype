typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { float m[9]; u8 on; char pad; short id; float r; } Col;
typedef struct { u8 b0; u8 b1; u16 s[3]; Col *c[3]; int v20; int v24; } Hdr;
typedef struct { char pad[208]; Hdr *h; } Obj;
extern char D_800F2758[];
extern int func_800AA804(void *, void *, int, char *);
void func_800AD890(Obj *o, u8 n)
{
    u8 i;
    Col *c;
    if (o->h == 0) {
        if (func_800AA804(D_800F2758, &o->h, 28, "CSHAPE")) return;
        o->h->b0 = 0;
        o->h->b1 = 0;
        i = 0;
        while (1) {
            if (!(i < 3)) break;
            o->h->s[i] = 0;
            o->h->c[i] = 0;
            i++;
        }
        o->h->v20 = 0;
        o->h->v24 = 0;
    }
    o->h->s[0] = n;
    if (func_800AA804(D_800F2758, &o->h->c[0], o->h->s[0] * 72, "COLSHAPE")) {
        o->h->s[0] = 0;
        return;
    }
    o->h->b0 = 1;
    o->h->b1 = 1;
    o->h->v20 = 0;
    c = o->h->c[0];
    c->m[0] = c->m[1] = c->m[2] = c->m[3] = c->m[4] = c->m[5] = c->m[6] = c->m[7] = c->m[8] = 0.0f;
    c->on = 1;
    c->id = -1;
    c->r = 100.0f;
}
