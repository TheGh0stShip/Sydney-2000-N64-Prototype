typedef struct {
    float x;
    float y;
    float z;
} Vec;

typedef struct {
    char p0[12];
    Vec pos;
} Node;

typedef struct {
    char p0[8];
    Node *node;
} Model;

typedef struct {
    char p0[84];
    Vec pos;
    char p60[76];
    int f172;
    char pB0[20];
    int f196;
    char pC8[8];
    Model *model;
    Vec d1;
    Vec a;
    Vec d2;
    Vec b;
} Obj;

extern void func_800AD890(Obj *o, int n);
extern void func_800ADC54(Obj *o, int n);

static inline void vsub(Vec *d, Vec *p, Vec *q)
{
    d->x = p->x - q->x;
    d->y = p->y - q->y;
    d->z = p->z - q->z;
}

void func_80080FA8(Obj *o, int mode, float y, float x, float z)
{
    Node *n;

    o->f196 = mode;
    o->pos.x = x;
    o->pos.y = y;
    o->pos.z = z;
    o->a.x = o->pos.x;
    o->a.y = 0.0f;
    o->a.z = o->pos.z + 11.7961206f;
    vsub(&o->d1, &o->pos, &o->a);
    o->b.x = o->pos.x;
    o->b.y = 0.0f;
    o->b.z = o->pos.z - 11.7961206f;
    vsub(&o->d2, &o->pos, &o->b);
    func_800AD890(o, 1);
    n = o->model->node;
    n->pos.x = o->pos.x;
    n->pos.y = o->pos.y;
    n->pos.z = o->pos.z;
    func_800ADC54(o, 1);
    o->f172 = 0;
}
