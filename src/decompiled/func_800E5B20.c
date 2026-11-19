#include "sydney_types.h"

/* Per-frame particle update: fades slot colours, then moves each live particle (falling or orbiting). */
typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0xC];
    f32 gravity;
    Vec3f vel;
    Vec3f pos;
    Vec3f rel;
    Vec3f unk_34;
    Vec3f prevPos;
    u8 pad4C[0x64 - 0x4C];
} Particle;

typedef struct {
    s32 colour;
    s32 flags;
} ParticleSlot;

typedef struct Emitter {
    u8 pad0[0x14];
    u8 unk_14[0x54 - 0x14];
    Vec3f pos;
    u8 pad60[0xD8 - 0x60];
    s32 unk_D8;
    s32 count;
    Particle *particles;
    ParticleSlot *slots;
} Emitter;

extern void func_800AD2A8(void *arg0, Vec3f *in, Vec3f *out, s32 arg3);
extern void func_800AD9E8(Emitter *e);

static inline void Vec3f_Copy(Vec3f *src, Vec3f *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

static inline void Vec3f_Add(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->x + b->x;
    dst->y = a->y + b->y;
    dst->z = a->z + b->z;
}

static inline void Vec3f_Sub(Vec3f *dst, Vec3f *a, Vec3f *b) {
    dst->x = a->x - b->x;
    dst->y = a->y - b->y;
    dst->z = a->z - b->z;
}

void func_800E5B20(Emitter *e) {
    s32 i;
    s32 flags;

    if (e->unk_D8 != 0) {
        return;
    }
    i = e->count;
    while (--i != -1) {
        if (e->slots[i].flags & 1) {
            e->slots[i].colour -= 0x100;
            if (e->slots[i].colour <= 0) {
                e->slots[i].flags &= ~1;
            }
        }
    }
    i = e->count;
    while (1) {
        if (--i == -1) {
            break;
        }
        if (!(e->slots[i].flags & 1)) {
            continue;
        }
        Vec3f_Copy(&e->particles[i].pos, &e->particles[i].prevPos);
        flags = e->slots[i].flags;
        if (flags & 2) {
            e->particles[i].vel.y += e->particles[i].gravity;
            Vec3f_Add(&e->particles[i].pos, &e->particles[i].pos, &e->particles[i].vel);
            Vec3f_Sub(&e->particles[i].rel, &e->particles[i].pos, &e->pos);
            Vec3f_Copy(&e->particles[i].rel, &e->particles[i].unk_34);
        } else if (flags & 4) {
            e->particles[i].vel.y -= e->particles[i].gravity;
            Vec3f_Add(&e->particles[i].rel, &e->particles[i].rel, &e->particles[i].vel);
            func_800AD2A8(e->unk_14, &e->particles[i].rel, &e->particles[i].pos, 1);
            Vec3f_Sub(&e->particles[i].unk_34, &e->particles[i].pos, &e->pos);
        }
    }
    func_800AD9E8(e);
}
