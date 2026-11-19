#include "sydney_types.h"

/* One-time setup of the chain object (loads its models, creates the body and the 18 segment parts), then resets its animation and motion state. */
typedef struct Vec4 { f32 v[4]; } Vec4;
typedef struct Res { u8 pad[0xC]; s32 *data; } Res;
typedef struct Shape { u8 pad[0x28]; f32 scale; } Shape;
typedef struct Model { u8 pad[8]; Shape *shape; } Model;
typedef struct Part {
    u8 pad00[0xC0];
    s32 flags;
    u8 padC4[0xC];
    Model *model;
    u8 padD4[0xC];
    s32 unk_E0;
    u8 padE4[8];
    s32 unk_EC;
    s32 unk_F0;
} Part;
typedef struct Seg {
    u8 pad00[0xC0];
    s32 flags;
    s32 model;
    u8 padC8[0xC];
} Seg;
typedef struct Chain {
    Part base;
    u8 padF4[0xA0];
    s32 unk_194;
    s32 models[8];
    Seg segs[16];
    Seg ends[2];
    s32 unk_10A0;
    u8 pad10A4[4];
    f32 unk_10A8;
    f32 unk_10AC;
    f32 unk_10B0;
    f32 unk_10B4;
    f32 unk_10B8;
    u8 pad10BC[4];
    f32 unk_10C0;
    s32 ready;
} Chain;

extern char D_80080A20[];
extern char D_80080A44[];
extern char D_80080A6C[];
extern char D_80080A90[];
extern char D_80080AB4[];
extern char D_80080AD8[];
extern char D_80080AFC[];
extern char D_80080B20[];
extern char D_80080B48[];
extern u8 D_80065BB0;

void func_80013E7C(char *, Res **, s32);
s32 func_800140A0(char *, s32, s32);
void func_800148F8(Chain *, void *);
void func_800AD890(void *, s32);
void func_800ADC54(void *, s32);
void func_800B7130(Chain *, s32, s32, s32, s32);
void func_800B9AD0(Chain *);
void func_800B9BD4(Chain *, s32, Vec4 *, f32 *, Vec4 *, s32);
void func_800B9E74(Chain *, s32);
void func_800B9E9C(Chain *, s32, s32, f32, s32);
void func_800B9FA4(Chain *, s32, s32, f32, s32, s32);
s32 func_800BA2D0(char *);

static inline void seg_show(Seg *s) {
    s->flags |= 0x600;
    s->flags = (s->flags & ~0x600) | 0x2000000;
}

void func_80080C80(Chain *this) {
    Vec4 a;
    Vec4 c;
    Res *res;
    f32 b;
    u32 i;

    if (this->ready == 0) {
        this->unk_194 = func_800140A0(D_80080A20, -1, 1);
        this->unk_10A0 = func_800BA2D0(D_80080A44);
        func_80013E7C(D_80080A6C, &res, 0);
        this->models[0] = *res->data;
        func_80013E7C(D_80080A90, &res, 0);
        this->models[1] = *res->data;
        func_80013E7C(D_80080AB4, &res, 0);
        this->models[2] = *res->data;
        func_80013E7C(D_80080AD8, &res, 0);
        this->models[3] = *res->data;
        func_80013E7C(D_80080AFC, &res, 0);
        this->models[4] = *res->data;
        func_80013E7C(D_80080B20, &res, 0);
        this->models[5] = *res->data;
        this->models[6] = *res->data;
        func_80013E7C(D_80080B48, &res, 0);
        this->models[7] = *res->data;
        func_800B7130(this, this->unk_194, this->unk_10A0, 0, 0);
        this->base.unk_E0 = 0x14;
        func_800B9AD0(this);
        func_800ADC54(this, 1);
        this->base.flags |= 0x600;
        func_800AD890(this, 1);
        this->base.model->shape->scale = 26.213598f;
        i = 0;
        while (1) {
            if (i >= 16) {
                break;
            }
            this->segs[i].model = this->models[0];
            func_800ADC54(&this->segs[i], 1);
            seg_show(&this->segs[i]);
            func_800AD890(&this->segs[i], 1);
            i++;
            this->base.model->shape->scale = 16.3835f;
        }
        i = 0;
        while (1) {
            if (i >= 2) {
                break;
            }
            this->ends[i].model = this->models[7];
            func_800ADC54(&this->ends[i], 1);
            seg_show(&this->ends[i]);
            func_800AD890(&this->ends[i], 1);
            i++;
            this->base.model->shape->scale = 16.3835f;
        }
        this->ready = 1;
        this->base.flags = (this->base.flags & ~0x600) | 0x2000000;
    }
    func_800B9FA4(this, 0, 3, 1.0f, 0, 1);
    func_800B9E9C(this, 0, 3, 1.0f, 0);
    this->base.unk_EC = 0;
    this->base.unk_F0 = 0;
    func_800B9E74(this, 4);
    this->unk_10A8 = this->unk_10AC = this->unk_10B0 = this->unk_10B4 = this->unk_10B8 = this->unk_10C0 = 0.0f;
    func_800148F8(this, &D_80065BB0);
    func_800B9BD4(this, 1, &a, &b, &c, 0);
}
