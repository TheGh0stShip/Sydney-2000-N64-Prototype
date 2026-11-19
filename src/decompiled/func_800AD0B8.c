#include "sydney_types.h"

/* Linear blend of quaternion a toward b by t, flipping b to the same hemisphere first. */
typedef struct { f32 x, y, z, w; } Quat;

void func_800AD0B8(Quat *a, Quat *b, f32 t, Quat *out) {
    Quat q;

    if (a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w < 0.0f) {
        q.x = -b->x;
        q.y = -b->y;
        q.z = -b->z;
        q.w = -b->w;
    } else {
        q.x = b->x;
        q.y = b->y;
        q.z = b->z;
        q.w = b->w;
    }
    out->x = a->x + (q.x - a->x) * t;
    out->y = a->y + (q.y - a->y) * t;
    out->z = a->z + (q.z - a->z) * t;
    out->w = a->w + (q.w - a->w) * t;
}
