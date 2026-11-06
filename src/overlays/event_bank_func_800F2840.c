typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Inner {
    char pad0[0x40];
    Vec3 pos;
} Inner;

typedef struct Obj {
    char pad0[0x14];
    Inner inner;
    char pad60[0x170 - 0x60];
    Vec3 rel;
    char pad17C[0x1110 - 0x17C];
    Vec3 origin;
} Obj;

extern void func_800B9BD4(Obj *obj, int mode, Vec3 *a, float *b, Vec3 *c, int flag);
extern void func_800B9964(Obj *obj, Vec3 *a, float *b, Vec3 *c);

void func_800F2840(Obj *obj)
{
    Vec3 a;
    Vec3 c;
    float b[2];
    Inner *in;
    Vec3 *p;
    Vec3 *r;
    Vec3 *o;

    p = &obj->inner.pos;
    p->x = *(float *)0x80078B70;
    p->y = 0.0f;
    p->z = *(float *)0x80078B74;
    in = &obj->inner;
    r = &obj->rel;
    r->x = in->pos.x;
    r->y = in->pos.y;
    r->z = in->pos.z;
    o = &obj->origin;
    r->x -= o->x;
    r->y -= o->y;
    r->z -= o->z;
    func_800B9BD4(obj, 1, &a, b, &c, 0);
    func_800B9964(obj, &a, b, &c);
}
