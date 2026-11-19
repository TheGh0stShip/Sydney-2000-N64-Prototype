#include "sydney_types.h"

/* Message handler: dispatches on the message type, then advances the object's timestamp to the message's. */
typedef union Arg {
    u32 w;
    u8 b[4];
} Arg;

typedef struct Msg {
    s32 type;
    s32 time;
    u8 pad08[8];
    Arg arg;
} Msg;

typedef struct Pad {
    u8 unk_00;
    u8 unk_01;
    u8 released;
    u8 pressed;
} Pad;

typedef struct Obj {
    u8 pad0000[0x10];
    s32 time;
    u8 pad0014[0xF14 - 0x14];
    s32 unk_F14;
    u8 pad0F18[4];
    Pad *pad;
    u8 pad0F20[0x42E8 - 0xF20];
    u8 unk_42E8[4];
    s32 unk_42EC;
    u8 pad42F0[0x4D70 - 0x42F0];
    s32 unk_4D70;
    s32 unk_4D74;
    s32 unk_4D78;
    s32 unk_4D7C;
    s32 unk_4D80;
} Obj;

typedef struct G {
    u8 pad[0xD1B];
    u8 unk_D1B;
    u8 padD1C[3];
    u8 unk_D1F;
} G;

extern G *D_800FC270;
extern u8 D_800F2AD8[];
extern u8 D_800F2758[];

void func_80015EAC(s32 a);
void func_800177AC(void);
void func_80071688(Obj *obj, s32 dt);
void func_80072044(Obj *obj);
void func_800723CC(Obj *obj, s32 a, s32 b);
void func_800828B4(Obj *obj, s32 a);
void func_80083700(Obj *obj, s32 a);
void func_80083A0C(Obj *obj);
void func_800AA658(u8 *a, u8 *b);
void func_800BBD78(u8 *a, s32 b, s32 c, Obj *obj, s32 e);
void func_800BC07C(Pad *pad, s32 a);

void func_800D36B0(Obj *obj, Msg *msg) {
    s32 dt;
    u8 bits;
    Arg *arg;

    dt = (msg->time - obj->time) >> 8;
    switch (msg->type) {
    case 3:
        func_80015EAC(12);
        func_800723CC(obj, D_800FC270->unk_D1B, D_800FC270->unk_D1F);
        func_80072044(obj);
        func_800177AC();
        break;
    case 7:
        switch (msg->arg.w) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, obj, 0);
            break;
        case 7:
        case 0x39:
            func_800AA658(D_800F2758, obj->unk_42E8);
            func_800828B4(obj, msg->arg.w);
            break;
        }
        break;
    case 1:
        func_80083700(obj, msg->arg.w);
        break;
    case 2:
        arg = &msg->arg;
        if (obj->unk_4D70 == 1) {
            func_800BC07C(obj->pad, arg->b[1]);
            bits = obj->pad->pressed;
            if (bits & 4) {
                obj->unk_4D74 = 1;
            }
            if (bits & 8) {
                obj->unk_4D78 = 1;
            }
            if (bits & 1) {
                obj->unk_4D80 = 1;
            }
            if (bits & 2) {
                obj->unk_4D7C = 1;
            }
            bits = obj->pad->released;
            if (bits & 4) {
                obj->unk_4D74 = 0;
            }
            if (bits & 8) {
                obj->unk_4D78 = 0;
            }
            if (bits & 1) {
                obj->unk_4D80 = 0;
            }
            if (bits & 2) {
                obj->unk_4D7C = 0;
            }
        } else if (obj->unk_42EC == 0) {
            func_800BC07C(obj->pad, arg->b[1]);
            if (obj->pad->pressed != 0) {
                obj->unk_F14 = 1;
            }
        } else {
            func_800BC07C(obj->pad, arg->b[1]);
        }
        func_80071688(obj, dt);
        break;
    case 5:
        func_80083A0C(obj);
        func_80071688(obj, dt);
        break;
    case 12:
        break;
    }
    obj->time = msg->time;
}
