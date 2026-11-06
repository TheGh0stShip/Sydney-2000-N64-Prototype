typedef struct { float x, y, z; } Vec3;
typedef struct {
    char pad0[0x14];
    char xform[0x54 - 0x14];
    Vec3 offset;            /* 0x54 */
    char pad60[0xAC - 0x60];
    int dirty;              /* 0xAC */
    char padB0[0xD4 - 0xB0];
    char anchor[0xE0 - 0xD4]; /* 0xD4 */
    Vec3 target;            /* 0xE0 */
    float angle;            /* 0xEC */
    float dist;             /* 0xF0 */
    int unkF4;
    int unkF8;
    float speed;            /* 0xFC */
    short state;            /* 0x100 */
    short timer;            /* 0x102 */
} Cam;

extern void func_800AD58C(void *xf, float angle, float dist, int flag);
extern void func_800AD2A8(void *xf, void *anchor, Vec3 *out, int flag);
extern void func_800AD9E8(Cam *c);

#define VEC3_SUB(d, a, b) ((d)->x = (a)->x - (b).x, (d)->y = (a)->y - (b).y, (d)->z = (a)->z - (b).z)

void func_8011DDE0(Cam *c, float angle, float step, float speed)
{
    Vec3 pos;

    step += step;
    if (c->dist >= 0.0f) {
        c->dist += step;
        if (c->dist > *(float *)0x80080AE8) {
            c->dist = *(float *)0x80080AE8;
        }
    } else {
        c->dist -= step;
        if (c->dist < *(float *)0x80080AEC) {
            c->dist = *(float *)0x80080AEC;
        }
    }
    c->angle = angle;
    c->state = 1;
    c->timer = 30;
    c->speed = speed;
    c->unkF4 = 0;
    c->unkF8 = 0;
    c->dirty = 1;
    func_800AD58C(c->xform, c->angle, c->dist, 0);
    func_800AD2A8(c->xform, c->anchor, &pos, 0);
    {
        Vec3 *a = &c->target;
        Vec3 *d = &c->offset;
        VEC3_SUB(d, a, pos);
    }
    func_800AD9E8(c);
}
