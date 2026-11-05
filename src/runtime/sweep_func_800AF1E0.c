typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    int unk0;
    Vec3 p[4];
} Curve;

void func_800AF1E0(void *unused, Curve *c, float t, Vec3 *out) {
    float t2 = t * t;
    float u = 1.0f - t;
    float u2 = u * u;
    float b0 = u2 * u;
    float b1 = (t + t + t) * u2;
    float b2 = (t2 + t2 + t2) * u;
    float b3 = t2 * t;

    out->x = b0 * c->p[0].x;
    out->x += b1 * c->p[1].x;
    out->x += b2 * c->p[2].x;
    out->x += b3 * c->p[3].x;
    out->y = b0 * c->p[0].y;
    out->y += b1 * c->p[1].y;
    out->y += b2 * c->p[2].y;
    out->y += b3 * c->p[3].y;
    out->z = b0 * c->p[0].z;
    out->z += b1 * c->p[1].z;
    out->z += b2 * c->p[2].z;
    out->z += b3 * c->p[3].z;
}
