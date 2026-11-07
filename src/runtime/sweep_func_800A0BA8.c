typedef signed int s32;
typedef float f32;
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Vtx { Vec3 p; Vec3 n; f32 pad[3]; } Vtx;
typedef struct Pt { Vec3 a; f32 pad[3]; Vec3 b; f32 pad2[4]; } Pt;
typedef struct Grid { char pad[0xB8]; s32 w; s32 h; s32 padC0; Pt *pts; } Grid;
extern s32 func_80017C4C(s32, s32, Vtx **);
extern s32 func_80017C3C(s32);
extern void func_800AD6D0(Vec3 *, Vec3 *);
void func_800A0BA8(char *o)
{
    Vtx *buf;
    Grid *g;
    Pt *s;
    s32 w, h, cnt, i;
    f32 k;

    func_80017C4C(*(s32 *)(o + 196), 0, &buf);
    g = (Grid *)(o + 244);
    w = g->w;
    h = g->h;
    s = g->pts;
    for (i = 0; i < w * h; i++, s++) {
        buf->p.x = s->a.x + s->b.x;
        buf->p.y = s->a.y + s->b.y;
        buf->p.z = s->a.z + s->b.z;
        buf++;
    }
    k = 0.5f;
    func_80017C4C(*(s32 *)(o + 196), 0, &buf);
    cnt = w * h;
    i = 0;
    while (1) {
        if (!(i < cnt)) break;
        if (i != 0 && i != cnt) {
            Vec3 *n;
            buf->n.x = buf[-1].p.y - buf[1].p.y;
            n = &buf->n;
            n->y = k;
            n->z = 0;
            func_800AD6D0(n, n);
        }
        i++;
        buf++;
    }
    func_80017C3C(*(s32 *)(o + 196));
}
