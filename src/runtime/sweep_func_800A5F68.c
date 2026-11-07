typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct { char pad[0xB4]; VEnt *vt; char rest[212 - 0xB8]; } A212;
typedef struct { char pad[0xB4]; VEnt *vt; char rest[220 - 0xB8]; } A220;
typedef struct { char pad[0xB4]; VEnt *vt; char rest[236 - 0xB8]; } A236;
typedef struct {
    char pad0[0x120];
    A236 c[6];
    A220 b[6];
    A220 a[6];
    char base[0x11DC - 0x10F8];
    char s3[0x12B0 - 0x11DC];
    char s2[0x1384 - 0x12B0];
    char s1[0x1458 - 0x1384];
    char s0[0x152C - 0x1458];
    A212 z[6];
    A212 y[6];
    char pad1f1c[0x10];
    A212 x[4];
} Menu;

extern VEnt D_80086598[];
extern void func_800ADE84(void *p, int f);
extern void func_800ADDA4(void *p, int f);
extern void func_800AC3A4(Menu *m, int f);

void func_800A5F68(Menu *m, int flag)
{
    A212 *e;
    A220 *f;
    A236 *g;

    if (m->x != 0) {
        e = m->x + 4;
        while (m->x != e) {
            e--;
            e->vt[1].fn((char *)e + e->vt[1].adj, 2);
        }
    }
    if (m->y != 0) {
        e = m->y + 6;
        while (m->y != e) {
            e--;
            e->vt[1].fn((char *)e + e->vt[1].adj, 2);
        }
    }
    if (m->z != 0) {
        e = m->z + 6;
        while (m->z != e) {
            e--;
            e->vt[1].fn((char *)e + e->vt[1].adj, 2);
        }
    }
    func_800ADE84(m->s0, 2);
    func_800ADE84(m->s1, 2);
    func_800ADE84(m->s2, 2);
    func_800ADE84(m->s3, 2);
    f = (A220 *)m->base;
    f->vt = D_80086598;
    func_800ADDA4(f, 2);
    if (m->a != 0) {
        f = m->a + 6;
        while (m->a != f) {
            f--;
            f->vt[1].fn((char *)f + f->vt[1].adj, 2);
        }
    }
    if (m->b != 0) {
        f = m->b + 6;
        while (m->b != f) {
            f--;
            f->vt[1].fn((char *)f + f->vt[1].adj, 2);
        }
    }
    if (m->c != 0) {
        g = m->c + 6;
        while (m->c != g) {
            g--;
            g->vt[1].fn((char *)g + g->vt[1].adj, 2);
        }
    }
    func_800AC3A4(m, flag);
}
