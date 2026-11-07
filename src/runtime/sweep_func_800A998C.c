typedef struct { float x, y, z; } Vector3;
typedef struct { float m[16]; Vector3 position; } MotionTransform;
typedef struct { short offset; short pad; void (*fn)(void *); } VEntry;
typedef struct { char pad[24]; VEntry handle; } VTable;
typedef struct Obj {
    char pad0[4]; struct Obj *parent; char pad1[12];
    MotionTransform transform;
    char pad2[84]; VTable *vt;
    unsigned char useY, useX, useZ, identity;
} Obj;
extern void func_800B3870(void *, void *, int);
void func_800A998C(Obj *o, int *msg)
{
    switch (*msg) {
    case 5:
        if (o->parent) {
            Vector3 saved;
            MotionTransform *t = &o->transform;
            Vector3 *s = &saved;
            s->x = t->position.x;
            s->y = t->position.y;
            s->z = t->position.z;
            if (o->identity) {
                float one = 1.0f;
                Vector3 *p = &o->transform.position;
                t->m[9] = 0; t->m[8] = 0; t->m[6] = 0; t->m[4] = 0; t->m[2] = 0; t->m[1] = 0;
                t->position.z = 0; t->position.y = 0; t->position.x = 0;
                t->m[10] = one; t->m[5] = one; o->transform.m[0] = one;
                {
                    MotionTransform *pt = &o->parent->transform;
                    p->x = pt->position.x;
                    p->y = pt->position.y;
                    p->z = pt->position.z;
                }
            } else {
                func_800B3870(t, &o->parent->transform, 76);
            }
            if (o->useY) o->transform.position.y = saved.y;
            if (o->useX) o->transform.position.x = saved.x;
            if (o->useZ) o->transform.position.z = saved.z;
        }
        break;
    case 3:
        break;
    case 7:
        if (o->parent) o->vt->handle.fn((char *)o + o->vt->handle.offset);
        break;
    }
}
