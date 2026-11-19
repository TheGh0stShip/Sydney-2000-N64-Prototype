#include "sydney_types.h"

/* Initializes an object from its placement definition and dispatches type-specific setup. */
typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Pose {
    u8 unk_00[0x40];
    Vec3 pos;
} Pose;

typedef struct Def {
    u8 unk_00[4];
    s32 flags;
    u8 unk_08[4];
    s16 x;
    s16 y;
    u8 unk_10[0xC];
    u8 *unk_1C;
} Def;

typedef struct Obj {
    u8 unk_000[0x60];
    Pose pose;
    u8 unk_0AC_pad[0xAC - 0x60 - sizeof(Pose)];
    s32 unk_0AC;
    u8 unk_0B0;
    u8 unk_0B1[0xDC - 0xB1];
    Def *def;
    u8 unk_0E0[0x310 - 0xE0];
    s32 unk_310;
    u8 unk_314;
    u8 unk_315[7];
    u8 unk_31C;
    u8 unk_31D;
    u8 unk_31E;
    u8 unk_31F;
    u8 unk_320;
    u8 unk_321;
    u8 unk_322[2];
    s32 unk_324;
    s32 unk_328;
} Obj;

typedef struct Pad {
    u8 unk_00[0xD8];
    s32 unk_D8;
} Pad;

extern s32 D_800F26A8;
extern Pad *D_800F63F0;

void func_800ADC54(Obj *obj, s32 mask);
void func_800AFD00(Obj *obj, s32 a, s32 b);
void func_800B0040(Obj *obj);
void func_800B06A8(Obj *obj, s32 a);
void func_800B0CEC(Obj *obj, s32 a);
void func_800B0E3C(Obj *obj);
void func_800B0F60(Obj *obj);
void func_800B1A54(Obj *obj);
void func_800B1BE8(Obj *obj);
void func_800C0DF0(Obj *obj);
void func_800C1540(Obj *obj, s32 a, s32 b);
void func_800C1D88(Obj *obj, s32 a);
void func_800C4104(Obj *obj);
void func_800C4A9C(Obj *obj);
void func_800C4E90(Obj *obj);
void func_800C6D74(Obj *obj);

void func_800AFA50(Obj *obj, s32 unused, Def *def, s32 arg3) {
    s32 active = 1;
    s32 flags;
    Pose *pose;
    s32 x;
    s32 y;

    D_800F26A8 = 0;
    obj->unk_314 = 0xFF;
    obj->unk_31C = 0x3D;
    obj->unk_31D = 0x64;
    obj->unk_31E = 0xC0;
    obj->unk_31F = 0x3D;
    obj->unk_320 = 0x64;
    obj->unk_321 = 0xC0;
    obj->unk_324 = 0;
    obj->unk_328 = 4;
    obj->def = def;
    x = def->x;
    y = def->y;
    pose = &obj->pose;
    obj->unk_0AC = 0;
    pose->pos.z = 0.0f;
    pose->pos.x = x;
    pose->pos.y = y;
    obj->unk_0B0 = 1;
    func_800ADC54(obj, 1 << D_800F63F0->unk_D8);
    flags = obj->def->flags;
    if (flags & 0x10000) {
        func_800B0040(obj);
        flags &= 0xFFFF;
        if (flags == 0x11) {
            func_800B0E3C(obj);
        }
    } else {
        if (flags & 0x20000) {
            active = 0;
        }
        if (flags & 0x200000) {
            obj->unk_310 = 1;
            func_800B06A8(obj, 1);
        }
        flags &= 0xFFFF;
        switch (flags) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 26:
        case 29:
            if (obj->def->y != 0xF && active) {
                if (obj->def->flags & 0x400000) {
                    func_800AFD00(obj, arg3, 1);
                } else {
                    func_800AFD00(obj, arg3, 0);
                }
            }
            break;
        case 3:
            func_800B1A54(obj);
            func_800C6D74(obj);
            break;
        case 4:
        case 5:
            obj->def->unk_1C[1] = 0;
            func_800C4104(obj);
            break;
        case 27:
            func_800C0DF0(obj);
            if (active) {
                func_800AFD00(obj, 1, 0);
            }
            break;
        case 30:
            func_800C1D88(obj, 0);
            break;
        case 10:
        case 11:
        case 12:
            func_800C1540(obj, obj->def->flags & 0x40000, obj->def->flags & 0x1000000);
            if (obj->def->flags & 0x40000) {
                func_800B1BE8(obj);
            }
            if (active) {
                func_800AFD00(obj, arg3, 0);
            }
            break;
        }
    }
    if (flags == 5) {
        func_800C4E90(obj);
    } else if (flags == 4) {
        func_800C4A9C(obj);
    } else {
        func_800B0F60(obj);
    }
    func_800B0CEC(obj, obj->def->flags & 0x80000);
}
