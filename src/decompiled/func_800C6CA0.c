#include "sydney_types.h"

/* Message handler of an event object: dispatches on the message id, then records the message time. */
typedef struct Msg { s32 id; s32 time; s32 unk_08; s32 unk_0C; union { u32 i; u8 b[4]; } arg; } Msg;
typedef struct Pad { u8 b0, b1, b2, b3; } Pad;
typedef struct Glob { u8 p[0xD1B]; u8 unk_D1B; u8 p2[3]; u8 unk_D1F; } Glob;
typedef struct Obj {
    u8 p0[0x10]; s32 unk_10; u8 p1[0xF14 - 0x14]; s32 unk_F14; u8 p2[4]; Pad *unk_F1C;
    u8 p3[0x42E8 - 0xF20]; s32 unk_42E8; s32 unk_42EC; u8 p4[0x44D4 - 0x42F0]; s32 unk_44D4;
} Obj;
extern void func_80015EAC(s32);
extern void func_80070B74(Obj *, s32, s32);
extern void func_8007173C(Obj *);
extern void func_800177AC(void);
extern void func_800BBD78(void *, s32, s32, Obj *, s32);
extern void func_800AA658(void *, s32 *);
extern void func_800828B4(Obj *, u32);
extern void func_80083700(Obj *, u32);
extern void func_800BC07C(Pad *, s32);
extern void func_80083A0C(Obj *);
extern void func_80070CC8(Obj *, s32);
extern Glob *D_800FC270;
extern u8 D_800F2AD8[], D_800F2758[];
void func_800C6CA0(Obj *o, Msg *m) {
    s32 dt = (m->time - o->unk_10) >> 8;

    switch (m->id) {
    case 3:
        func_80015EAC(0xC);
        func_80070B74(o, D_800FC270->unk_D1B, D_800FC270->unk_D1F);
        func_8007173C(o);
        func_800177AC();
        break;
    case 7:
        switch (m->arg.i) {
        case 8:
        case 0xF:
            func_800BBD78(D_800F2AD8, 0xC, 1, o, 0);
            break;
        case 7:
        case 0x39:
            func_800AA658(D_800F2758, &o->unk_42E8);
            func_800828B4(o, m->arg.i);
            break;
        }
        break;
    case 1:
        func_80083700(o, m->arg.i);
        break;
    case 2: {
        u8 *b = m->arg.b;
        if (o->unk_42EC == 4 || o->unk_42EC == 5) {
            func_800BC07C(o->unk_F1C, b[1]);
            if (o->unk_F1C->b3 & 0x10) {
                o->unk_44D4 = 1;
            }
            if (o->unk_F1C->b2 & 0x10) {
                o->unk_44D4 = 0;
            }
        } else if (o->unk_42EC != 1) {
            func_800BC07C(o->unk_F1C, b[1]);
            if (o->unk_F1C->b3 != 0) {
                o->unk_F14 = 1;
            }
        }
        func_80070CC8(o, dt);
        break;
    }
    case 5:
        func_80083A0C(o);
        func_80070CC8(o, dt);
        break;
    case 12:
        break;
    }
    o->unk_10 = m->time;
}
