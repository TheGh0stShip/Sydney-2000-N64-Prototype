typedef unsigned char u8;
typedef struct { float x, y, z; } Vector3;
typedef struct { float m[16]; Vector3 position; } MotionTransform;
typedef struct {
    char pad0[20]; MotionTransform b;
    char pad1[96 - 96]; MotionTransform a;
    char pad2[176 - 172]; signed char flag;
} Node;
typedef struct {
    char pad0[188]; u8 count;
    char pad1[268 - 189]; Node *nodes[1];
} Obj;
extern void func_800AC9B8(Vector3 *, MotionTransform *, Vector3 *);
extern Vector3 *runtimeMotionUpVector;
static inline void rot(MotionTransform *s, MotionTransform *d)
{
    d->m[0] = s->m[0]; d->m[4] = s->m[4]; d->m[8] = s->m[8];
    d->m[1] = s->m[1]; d->m[5] = s->m[5]; d->m[9] = s->m[9];
    d->m[2] = s->m[2]; d->m[6] = s->m[6]; d->m[10] = s->m[10];
}
void func_800A7A64(Obj *o, Vector3 *dir)
{
    MotionTransform t;
    u8 i;
    Node *n;
    if (o->count == 0) return;
    func_800AC9B8(dir, &t, runtimeMotionUpVector);
    i = 0;
    while (1) {
        if (!(i < o->count)) break;
        n = o->nodes[i];
        if (n == 0) break;
        if (n->flag) rot(&t, &n->a);
        else rot(&t, &n->b);
        i++;
    }
}
