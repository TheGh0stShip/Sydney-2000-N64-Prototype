#include "sydney_types.h"

/* Sums several part positions, then repositions the attached model from the result. */
typedef struct { f32 x, y, z; } Vec3;
typedef struct { f32 *unk_00; } Inner;
typedef struct { u8 unk_00[0xC]; Inner *unk_0C; } Model;
typedef struct {
    u8 unk_000[0x14];
    u8 unk_014[0x28C - 0x14];
    u8 unk_28C[0x310 - 0x28C];
    f32 unk_310;
    u8 unk_314;
    u8 unk_315;
    u8 unk_316[0x350 - 0x316];
    u8 unk_350[0x4C];
} Obj;
extern u8 D_80077280[];
Model *func_800AEF6C(void *, s32);
void func_800B9830(Obj *, s32, Vec3 *, s32, s32);
void func_800AEB68(void *, Model *);
void func_800AE72C(void *, Obj *, Model *);
void func_800AE9DC(void *, f32, Obj *);
void func_800B3870(void *, void *, s32);

static inline void vec_add(Vec3 *a, Vec3 *b) {
    a->x = b->x + a->x;
    a->y = b->y + a->y;
    a->z = b->z + a->z;
}

void func_8010746C(Obj *obj) {
    Model *model;
    Vec3 v;
    Vec3 sum;
    u8 i;
    f32 y;

    model = func_800AEF6C(D_80077280, 0);
    sum.x = 0.0f;
    sum.y = 0.0f;
    sum.z = 0.0f;
    func_800B9830(obj, 0xF, &v, 0, 0);
    obj->unk_310 = v.z;
    vec_add(&sum, &v);
    func_800B9830(obj, 0xC, &v, 0, 0);
    vec_add(&sum, &v);
    func_800B9830(obj, 0xD, &v, 0, 0);
    i = 0;
    while (1) {
        if (i >= 3) {
            break;
        }
        i++;
        vec_add(&sum, &v);
    }
    func_800B9830(obj, 0xE, &v, 0, 0);
    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        i++;
        vec_add(&sum, &v);
    }
    sum.z -= 16.383499145507812f;
    y = *model->unk_0C->unk_00 - sum.z * 1.5f;
    func_800AEB68(obj->unk_28C, model);
    func_800AE72C(obj->unk_28C, obj, model);
    func_800AE9DC(obj->unk_28C, y, obj);
    func_800B3870(obj->unk_350, obj->unk_014, 0x4C);
    obj->unk_315 = 0;
    obj->unk_314 = 0;
}
