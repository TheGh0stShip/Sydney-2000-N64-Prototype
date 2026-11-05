typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

struct Target {
    char pad[84];
    Vec3 pos;
    char pad2[1348 - 96];
    float radius;
};

struct Chaser {
    char pad[84];
    Vec3 pos;
    char pad2[236 - 96];
    int timerA;
    int timerB;
    float speed;
    float accel;
    char pad3[376 - 252];
    struct Target *target;
    float radiusA;
    char pad4[4];
    float radiusB;
    int count;
    unsigned char done;
};

extern Vec3 D_800FF470;
extern int D_800FF47C;
extern void func_800AE4FC(struct Chaser *);
extern void func_800E7AE0(struct Chaser *);

static __inline__ void vec3_add(Vec3 *out, Vec3 *a, Vec3 *b)
{
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}

void func_800E805C(struct Chaser *self, struct Target *target)
{
    float radius;

    func_800AE4FC(self);
    self->timerA = 5;
    self->timerB = 5;
    self->target = target;
    self->accel = 0.8f;
    self->speed = 0.837757945f;
    radius = target->radius;
    self->count = 0;
    self->done = 0;
    self->radiusA = radius;
    self->radiusB = radius;
    vec3_add(&self->pos, &D_800FF470, &self->target->pos);
    D_800FF47C = 1;
    func_800E7AE0(self);
}
