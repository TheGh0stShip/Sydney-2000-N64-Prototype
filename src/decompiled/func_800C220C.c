#include "sydney_types.h"

/* Per-frame state update: counts down a timer, picks an animation pair from the two input flags, then plays it on the body. */
typedef struct Vec4 { f32 v[4]; } Vec4;
typedef struct Vec2 { f32 v[2]; } Vec2;
typedef struct Body {
    u8 pad00[0x54];
    f32 unk_54;
    u8 pad58[4];
    f32 unk_5C;
} Body;
typedef struct Ctl { u8 pad[0xC0]; s32 flags; } Ctl;
typedef struct Obj {
    u8 pad0000[0xF0C];
    s32 timer;
    u8 padF10[0x2B8];
    Body body;
    u8 pad1228[0x30C4];
    s32 state;
    u8 pad42F0[0x7A0];
    Ctl ctl;
    u8 pad4B54[0x14];
    u16 unk_4B68;
    u8 pad4B6A[2];
    s32 anim;
    s32 anim2;
    s32 unk_4B74;
    u8 pad4B78[0x35];
    u8 unk_4BAD;
    u8 unk_4BAE;
    u8 pad4BAF;
    f32 unk_4BB0;
    f32 unk_4BB4;
    u8 pad4BB8[4];
    s32 unk_4BBC;
    u8 pad4BC0[4];
    s32 unk_4BC4;
    u8 pad4BC8[4];
    s32 unk_4BCC;
    s32 unk_4BD0;
    s32 unk_4BD4;
} Obj;

void func_80070CD0(Obj *);
void func_800B9964(Body *, Vec4 *, Vec2 *, Vec4 *);
s32 func_800B9BD4(Body *, s32, Vec4 *, Vec2 *, Vec4 *, s32);
void func_800B9E9C(Body *, s32, s32, f32, s32);
void func_800B9FA4(Body *, s32, s32, f32, s32, s32);

static inline void ctl_set(Ctl *c, s32 f) { c->flags |= f; }

void func_800C220C(Obj *this, s32 arg1) {
    Vec4 a;
    Vec4 c;
    Vec2 b;

    this->timer -= 0x100;
    if (this->timer <= 0) {
        this->state = 2;
    }
    if (this->unk_4B74 == this->unk_4B68) {
        this->state = 2;
        this->unk_4BBC = 0;
        ctl_set(&this->ctl, 4);
    }
    this->anim = 0;
    if (this->unk_4BC4 == 0) {
        if (this->unk_4BCC == 1 && this->unk_4BD4 == 1) {
            this->anim = 3;
            this->anim2 = 0xB;
            this->unk_4BAE = 1;
            if (this->unk_4BAD != 1) {
                this->anim2 = 0xF;
            }
            this->state = 7;
        } else if (this->unk_4BD0 == 1 && this->unk_4BD4 == 1) {
            this->anim = 5;
            this->anim2 = 0xD;
            this->unk_4BAE = 2;
            if (this->unk_4BAD != 2) {
                this->anim2 = 0x11;
            }
            this->state = 7;
        } else if (this->unk_4BCC == 1 && this->unk_4BD4 == 0) {
            this->anim = 2;
            this->anim2 = 0xA;
            this->unk_4BAE = 0;
            if (this->unk_4BAD != 0) {
                this->anim2 = 0xE;
            }
            this->state = 7;
        } else if (this->unk_4BD0 == 1 && this->unk_4BD4 == 0) {
            this->anim = 4;
            this->anim2 = 0xC;
            this->unk_4BAE = 3;
            if (this->unk_4BAD != 3) {
                this->anim2 = 0x10;
            }
            this->state = 7;
        } else {
            if (func_800B9BD4(&this->body, arg1, &a, &b, &c, 0) != 0) {
                this->unk_4BC4 = 0;
                func_800B9E9C(&this->body, this->anim, -1, 2.0f, 0);
            }
            func_800B9964(&this->body, &a, &b, &c);
        }
        if (this->state == 7) {
            this->body.unk_54 = 0.8742236f;
            this->body.unk_5C = -0.5444237f;
            func_800B9FA4(&this->body, this->anim, -1, this->unk_4BB4, 0, 1);
            func_800B9E9C(&this->body, this->anim2, -1, this->unk_4BB0, 0);
        }
    } else {
        if (func_800B9BD4(&this->body, arg1, &a, &b, &c, 0) != 0) {
            this->unk_4BC4 = 0;
            func_800B9E9C(&this->body, 0, -1, 2.0f, 0);
            if (this->unk_4BBC == 1) {
                func_80070CD0(this);
            }
        }
        func_800B9964(&this->body, &a, &b, &c);
    }
}
