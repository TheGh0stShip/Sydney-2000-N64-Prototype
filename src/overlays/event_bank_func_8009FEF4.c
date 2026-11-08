typedef unsigned char u8;
typedef struct Vec { float x, y, z; } Vec;
typedef struct Node { Vec p0; Vec p1; Vec n; } Node;
typedef struct Obj {
    char pad[0x49C];
    Node nodes[16];
    char pad6DC[0x6DC - (0x49C + 16 * 36)];
    u8 idx;
    char pad6DD[0x5CB0 - 0x6DD];
    char unk5CB0[4];
} Obj;
typedef struct Arg { char pad[0x54]; Vec pos; } Arg;
extern void func_800A9BE8(void *, int);
static inline float side(Vec *a, Vec *b, Vec *n, Vec *d)
{
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
    return n->x * d->x + n->y * d->y + n->z * d->z;
}
void func_8009FEF4(Obj *o, Arg *a)
{
    Vec d;
    int flag = 0;
    Node *n;
    while (1) {
        if (!(o->idx < 16)) break;
        n = &o->nodes[o->idx];
        if (!(side(&a->pos, &n->p1, &n->n, &d) < 0.0f)) break;
        flag = 1;
        o->idx++;
    }
    if (flag == 0) {
        while (1) {
            if (o->idx == 0) break;
            n = &o->nodes[o->idx - 1];
            if (!(0.0f <= side(&a->pos, &n->p0, &n->n, &d))) break;
            flag = 1;
            o->idx--;
        }
    }
    if (flag == 1) {
        func_800A9BE8(o->unk5CB0, (u8)(o->idx + 6));
    }
}
