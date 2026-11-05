/* Vector cross product: out = a x b. */
typedef struct { float x, y, z; } Vec3;

void func_800AD820(Vec3 *a, Vec3 *b, Vec3 *out)
{
    float p, q;

    p = a->y * b->z;
    q = a->z * b->y;
    out->x = p - q;
    p = a->z * b->x;
    q = a->x * b->z;
    out->y = p - q;
    p = a->x * b->y;
    q = a->y * b->x;
    out->z = p - q;
}
