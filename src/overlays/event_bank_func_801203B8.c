typedef struct V { float a[3]; char pad[12]; float b[3]; char pad2[52 - 36]; } V;
typedef struct Out { float x, y, z; char pad[36 - 12]; } Out;
typedef struct M { char pad[196]; int h; } M;
typedef struct Mesh { char pad[184]; int w; int hgt; char pad2[196 - 192]; V *verts; } Mesh;
typedef struct Obj {
    char pad[208];
    int mode;
    char padD4[216 - 212];
    M *ms[11];
    char pad104[260 - 260];
    Mesh mesh;
} Obj;
extern void func_80017C4C(int, int, Out **);
extern void func_80017C3C(int);
void func_80081238(Obj *o)
{
    Out *out;
    V *v;
    int i, n;
    Mesh *m;
    if (o->mode != -1) {
        func_80017C4C(o->ms[o->mode]->h, 0, &out);
        m = &o->mesh;
        n = m->w * m->hgt;
        v = m->verts;
        for (i = 0; i < n; i++, v++) {
            if (o->mode == 0 || o->mode == 10) {
                out->x = v->a[0] + v->b[0];
                out->y = (v->a[1] + v->b[1]) * 1.1825397014617920f;
                out->z = v->a[2] + v->b[2];
            } else {
                out->x = v->a[0] + v->b[0];
                out->y = v->a[1] + v->b[1];
                out->z = v->a[2] + v->b[2];
            }
            out++;
        }
        func_80017C3C(o->ms[o->mode]->h);
    }
}
