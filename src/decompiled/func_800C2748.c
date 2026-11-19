#include "sydney_types.h"

/* Per-frame update of a two-flag state machine: picks animation pair from the flags, else steps the body. */
typedef struct Vec4 { f32 x, y, z, w; } Vec4;
typedef struct Vec2 { f32 x, y; } Vec2;
typedef struct Body { u8 pad0[0x54]; f32 unk54; u8 pad58[4]; f32 unk5C; } Body;
typedef struct Obj {
    u8 pad0[0xF0C]; s32 timer; u8 padF10[0x11C8 - 0xF10]; Body body; u8 pad1228[0x42EC - 0x1228];
    s32 state; u8 pad42F0[0x4B6C - 0x42F0]; s32 animA; s32 animB; u8 pad4B74[0x4BAD - 0x4B74];
    u8 prevSide; u8 side; u8 pad4BAF; f32 speedA; f32 speedB; u8 pad4BB8[0x4BC4 - 0x4BB8];
    s32 busy; u8 pad4BC8[4]; s32 left; s32 right; s32 dir;
} Obj;
extern void func_80071CEC(Obj *o);
extern s32 func_800B9BD4(Body *b, s32 in, Vec4 *a, Vec2 *c, Vec4 *d, s32 e);
extern void func_800B9E9C(Body *b, s32 anim, s32 a, f32 speed, s32 c);
extern void func_800B9964(Body *b, Vec4 *a, Vec2 *c, Vec4 *d);
extern void func_800B9FA4(Body *b, s32 anim, s32 a, f32 speed, s32 c, s32 d);
void func_800C2748(Obj *o, s32 in)
{
    Vec4 a;
    Vec4 d;
    Vec2 c;

    if ((o->timer -= 0x100) <= 0) {
        o->state = 2;
    }
    func_80071CEC(o);
    if (o->busy != 0) {
        return;
    }
    if (o->left == 1 && o->dir == 1) {
        o->animA = 7;
        o->animB = 0xF;
        o->side = 1;
        if (o->prevSide != 1) {
            o->animB = 0xB;
        }
        o->state = 9;
    } else if (o->right == 1 && o->dir == 1) {
        o->animA = 9;
        o->animB = 0x11;
        o->side = 2;
        if (o->prevSide != 2) {
            o->animB = 0xD;
        }
        o->state = 9;
    } else if (o->left == 1 && o->dir == 0) {
        o->animA = 6;
        o->animB = 0xE;
        o->side = 0;
        if (o->prevSide != 0) {
            o->animB = 0xA;
        }
        o->state = 9;
    } else if (o->right == 1 && o->dir == 0) {
        o->animA = 8;
        o->animB = 0x10;
        o->side = 3;
        if (o->prevSide != 3) {
            o->animB = 0xC;
        }
        o->state = 9;
    } else {
        if (func_800B9BD4(&o->body, in, &a, &c, &d, 0) != 0) {
            o->busy = 0;
            func_800B9E9C(&o->body, 1, -1, 2.0f, 0);
        }
        func_800B9964(&o->body, &a, &c, &d);
    }
    if (o->state == 9) {
        o->body.unk54 = 0.8167175054550171f;
        o->body.unk5C = -0.5444236993789673f;
        func_800B9FA4(&o->body, o->animA, -1, o->speedA, 0, 1);
        func_800B9E9C(&o->body, o->animB, -1, o->speedB, 0);
    }
}
