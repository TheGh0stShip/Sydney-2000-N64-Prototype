typedef struct { float x, y, z; } Vec;
typedef struct { Vec p; char pad[52 - 12]; } Pt;
typedef struct { unsigned short a; unsigned short b; float len; } Edge;
typedef struct {
    char pad0[0xB8];
    int cols;
    int rows;
    char padc0[0xC4 - 0xC0];
    Pt *pts;
    char padc8[0xCC - 0xC8];
    Edge *edges;
} Mesh;

extern float func_800AD6D0(Vec *a, Vec *b);

static inline void vsub(Vec *o, Vec *a, Vec *b) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }

void func_8009FA40(Mesh *m)
{
    Edge *e;
    int i;
    int j;
    int k;
    Vec d;

    e = m->edges;
    j = 1;
    while (1) {
        if (j >= m->rows - 1) break;
        i = 0;
        while (1) {
            if (i >= m->cols - 1) break;
            k = m->cols * j + i;
            e->a = k;
            e->b = k + 1;
            vsub(&d, &m->pts[k].p, &m->pts[k + 1].p);
            e->len = func_800AD6D0(&d, &d);
            i++;
            e++;
        }
        j++;
    }
    i = 1;
    while (1) {
        if (i >= m->cols - 1) break;
        j = 0;
        while (1) {
            if (j >= m->rows - 1) break;
            k = m->cols * j + i;
            e->a = k;
            e->b = k + m->cols;
            vsub(&d, &m->pts[k].p, &m->pts[k + m->cols].p);
            e->len = func_800AD6D0(&d, &d);
            e++;
            j++;
        }
        i++;
    }
}
