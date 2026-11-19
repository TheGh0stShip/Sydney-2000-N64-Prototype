#include "sydney_types.h"

/* Event handler: on event 5, springs the object's position toward a tracked target point. */
typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x40];
    Vec3f pos;
} Body;

typedef struct {
    u8 pad0[0x14];
    u8 unk_14[1];
} Target;

typedef struct {
    s32 type;
    s32 time;
} Event;

typedef struct Follower {
    u8 pad0[0x10];
    s32 time;
    Body body;
    u8 pad60[0xC4 - 0x60];
    u16 flags;
    u8 padC6[0x10C - 0xC6];
    s32 unk_10C;
    u8 pad110[0x124 - 0x110];
    u8 unk_124[4];
    s32 unk_128;
    u8 pad12C[0x178 - 0x12C];
    void *unk_178;
    Target *target;
    u8 unk_180[0x18C - 0x180];
    Vec3f offset;
    Vec3f vel;
    f32 velScale;
    f32 offsetScale;
    u8 pad1AC[0x1CC - 0x1AC];
    f32 unk_1CC;
} Follower;

static inline void Vec3f_Sub(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->x - b->x;
    dst->y = a->y - b->y;
    dst->z = a->z - b->z;
}

static inline void Vec3f_Add(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->x + b->x;
    dst->y = a->y + b->y;
    dst->z = a->z + b->z;
}

static inline void Vec3f_Scale(Vec3f *v, f32 s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

static inline void Body_GetPos(Body *b, Vec3f *out) {
    out->x = b->pos.x;
    out->y = b->pos.y;
    out->z = b->pos.z;
}

extern void func_800AEAE8(void *arg0, Follower *arg1);
extern void func_800AD2A8(void *arg0, void *arg1, Vec3f *out, s32 arg3);
extern void func_800AEC9C(void *arg0, Vec3f *arg1);
extern void func_800BAF90(Follower *arg0);
extern void func_800B48CC(Follower *arg0, void *arg1, s32 arg2);
extern void func_800AE1EC(Follower *arg0, s32 time);
extern void func_800ADFAC(Follower *arg0);
extern void func_800AE304(Follower *arg0);

void func_800BAD00(Follower *obj, Event *event) {
    Vec3f tmp;
    Vec3f pos;
    s32 dt;

    dt = (event->time - obj->time) >> 8;
    switch (event->type) {
    case 3:
        break;
    case 5:
        if (obj->unk_178 != NULL && obj->target != NULL && dt != 0) {
            func_800AEAE8(obj->unk_124, obj);
            func_800AD2A8(obj->target->unk_14, obj->unk_180, &tmp, 1);
            Body_GetPos(&obj->body, &pos);
            Vec3f_Sub(&obj->vel, &tmp, &pos);
            Vec3f_Scale(&obj->vel, obj->velScale);
            Vec3f_Sub(&tmp, &obj->vel, &obj->offset);
            Vec3f_Scale(&tmp, obj->offsetScale);
            Vec3f_Add(&obj->offset, &tmp, &obj->offset);
            func_800AEC9C(obj->unk_124, &obj->offset);
            if (obj->unk_1CC < 1.0f) {
                func_800BAF90(obj);
            } else {
                func_800B48CC(obj, obj->unk_178, 0);
            }
            func_800AE1EC(obj, event->time);
        }
        break;
    }
    obj->time = event->time;
    if (obj->unk_128 == 0) {
        if (obj->unk_10C != 0) {
            func_800ADFAC(obj);
        }
        if (obj->flags & 1) {
            func_800AE304(obj);
        }
    }
}
