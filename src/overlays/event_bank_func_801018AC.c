typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Obj {
    char pad0[0x588];
    Vec3 pos;
    char pad594[0x608 - 0x594];
    Vec3 offset;
} Obj;

void func_801018AC(Obj *obj, Vec3 *v)
{
    Vec3 *p;

    v->x += obj->offset.x;
    v->z += obj->offset.z;
    p = &obj->pos;
    p->x = v->x;
    p->y = v->y;
    p->z = v->z;
}
