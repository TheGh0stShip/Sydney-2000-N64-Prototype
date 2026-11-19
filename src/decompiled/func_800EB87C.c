#include "sydney_types.h"

/* Spawns or moves effect entries at the actor's position depending on its current state. */
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Fx {
    u8 active;
    u8 unk_01;
    s16 unk_02;
    s32 unk_04;
    s32 unk_08;
    Vec3 pos;
    u8 pad18[0xC];
    f32 unk_24;
} Fx;
typedef struct FxList { u8 pad[0x1C]; } FxList;
typedef struct FxSys {
    u8 pad000[0x1F8];
    FxList listA;
    FxList listB;
    u8 pad230[0x1C];
    FxList listC;
} FxSys;
typedef struct World { u8 pad[0xC6A4]; FxSys fx; } World;
typedef struct Body { u8 pad00[0x40]; Vec3 pos; } Body;
typedef struct Actor {
    u8 pad00[4];
    World *world;
    u8 pad08[0xC];
    Body body;
    u8 pad60[0x4C];
    s32 state;
    u8 padB0[0x406];
    u8 unk_4B6;
    u8 pad4B7;
    s32 prevState2;
    s32 prevState;
} Actor;

Fx *func_800EA114(FxList *, s32);
void func_800EBE24(FxSys *, f32, f32, f32, f32);
void func_800EBE2C(FxSys *, f32, f32, f32, f32);

static inline void setPos(Fx *f, f32 x, f32 y, f32 z) {
    f->pos.x = x;
    f->pos.y = y;
    f->pos.z = z;
}

static inline void getPos(Body *b, Vec3 *out) {
    out->x = b->pos.x;
    out->y = b->pos.y;
    out->z = b->pos.z;
}

void func_800EB87C(Actor *this) {
    Vec3 pos;
    FxSys *sys;
    Fx *a;
    Fx *b;
    Fx *c;

    sys = &this->world->fx;
    getPos(&this->body, &pos);
    this->prevState2 = this->prevState;
    this->prevState = this->state;
    a = func_800EA114(&sys->listA, 0);
    b = func_800EA114(&sys->listB, 0);
    c = func_800EA114(&sys->listC, 0);
    switch (this->state) {
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
        this->unk_4B6 = 0;
        break;
    case 0x20:
        if (this->unk_4B6 == 0) {
            if (pos.y < 40.958748f) {
                this->unk_4B6 = 1;
                setPos(c, pos.x, pos.y, pos.z);
                c->unk_04 = 0x582;
                c->unk_02 = 0xB4;
                c->unk_08 = 0;
                c->active = 1;
                c->unk_01 = 0;
                c->unk_24 = 5.4611664f;
                func_800EBE2C(sys, pos.x, 0.0f, pos.z, 3.2766998f);
                func_800EBE24(sys, pos.x, 0.0f, pos.z, 3.2766998f);
                a->unk_04 = 0x384;
                a->unk_02 = -1;
                a->unk_08 = 0;
                a->active = 1;
                a->unk_01 = 0;
                setPos(a, pos.x, pos.y, pos.z);
                a->unk_24 = 5.4611664f;
            }
            break;
        }
        setPos(c, pos.x, pos.y, pos.z);
        setPos(a, pos.x, pos.y, pos.z);
        if (pos.y < 34.40535f) {
            f32 x = pos.x;
            f32 z = pos.z;
            b->pos.y = 0.0f;
            b->pos.x = x;
            b->pos.z = z;
        }
        break;
    case 0x21:
        setPos(c, pos.x, pos.y, pos.z);
        setPos(a, pos.x, pos.y, pos.z);
        break;
    case 0x22:
        a->active = 0;
        a->unk_01 = 0;
        a->unk_02 = 0;
        a = func_800EA114(&sys->listA, 1);
        a->unk_04 = 0x96;
        a->unk_02 = -1;
        a->unk_08 = 0;
        a->active = 1;
        a->unk_01 = 0;
        setPos(a, pos.x, pos.y, pos.z);
        a->unk_24 = 5.4611664f;
        break;
    case 0x23:
        a = func_800EA114(&sys->listA, 1);
        setPos(a, pos.x, pos.y, pos.z);
        break;
    }
}
