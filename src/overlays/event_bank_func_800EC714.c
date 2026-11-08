typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Body {
    char pad0[64];
    Vec3 pos;               /* 64 */
} Body;

typedef struct Obj {
    char pad0[20];
    Body body;              /* 20 */
    char pad1[368 - 96];
    Vec3 last;              /* 368 */
    char pad2[392 - 380];
    Vec3 prev;              /* 392 */
    char pad3[652 - 404];
    char link[4];           /* 652 */
} Obj;

extern char D_80077410[];

void *func_800AEF6C(char *name, int a);
void func_800AF0BC(void *h, Vec3 *v);
void func_800AF088(void *h, Vec3 *v);
void func_800AD6D0(Vec3 *in, Vec3 *out);
void func_800AE72C(char *link, Obj *o, void *h);
void func_800B9BD4(Obj *o, int a, Vec3 *b, float *c, Vec3 *d, int e);
void func_800B9964(Obj *o, Vec3 *b, float *c, Vec3 *d);

static inline void vsub(Vec3 *d, Vec3 *s)
{
    d->x -= s->x;
    d->y -= s->y;
    d->z -= s->z;
}

static inline void vscale(Vec3 *v, float s)
{
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

static inline void getpos(Vec3 *d, Body *b)
{
    d->x = b->pos.x;
    d->y = b->pos.y;
    d->z = b->pos.z;
}

void func_800EC714(Obj *o, int fast)
{
    Vec3 a;
    Vec3 dir;
    Vec3 v1;
    Vec3 v3;
    float v2[2];
    void *h;

    h = func_800AEF6C(D_80077410, 1);
    func_800AF0BC(h, &a);
    func_800AF088(h, &dir);
    vsub(&dir, &a);
    func_800AD6D0(&dir, &dir);
    func_800AE72C(o->link, o, func_800AEF6C(D_80077410, 1));
    if (fast) {
        vscale(&dir, 49.150497f);
    } else {
        vscale(&dir, 19.6602f);
    }
    vsub(&o->body.pos, &dir);
    getpos(&o->last, &o->body);
    getpos(&o->prev, &o->body);
    func_800B9BD4(o, 1, &v1, v2, &v3, 0);
    func_800B9964(o, &v1, v2, &v3);
}
