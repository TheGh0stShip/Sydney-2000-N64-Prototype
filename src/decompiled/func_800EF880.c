#include "sydney_types.h"

/* Event racer message handler: dispatches on the message type, updating pad state, timers and run state. */
typedef struct { s8 unk_0[8]; } PadBuf;
typedef struct { s16 unk_0; s16 unk_2; } Timer;
typedef struct { u8 pad[0x58]; f32 unk_58; u8 pad2[0x1B0 - 0x5C]; s32 unk_1B0; s32 unk_1B4; u8 pad3[4]; s32 unk_1BC; } Rival;
typedef struct { u8 pad[0xD4]; s32 unk_D4; } Board;
typedef struct { u8 pad[0x75AB]; u8 unk_75AB; } Scene;
typedef struct { s32 unk_0; f32 unk_4; s32 unk_8; } Clock;
typedef struct { u8 unk_0; u8 unk_1; } Pad;
typedef struct { s32 unk_0; s32 unk_4; u8 pad8[8]; union { s32 unk_10; Pad pad; } u; } Msg;
typedef struct {
    u8 pad0[4]; Scene *unk_4; u8 pad8[8]; s32 unk_10; u8 pad14[0xAC - 0x14]; s32 unk_AC;
    u8 padB0[0x1AA - 0xB0]; u8 unk_1AA; s8 unk_1AB; u8 pad1AC[0x284 - 0x1AC]; Timer *unk_284; PadBuf *unk_288;
    u8 pad28C[0x2DC - 0x28C]; u8 unk_2DC; u8 pad2DD[7]; s32 unk_2E4; u8 pad2E8[4]; s32 unk_2EC; s32 unk_2F0;
    u8 pad2F4[8]; s32 unk_2FC; s32 unk_300; u8 pad304[4]; s32 unk_308; s32 unk_30C; s32 unk_310;
    u8 pad314[0x320 - 0x314]; Rival *unk_320; s32 unk_324; Board *unk_328; u8 pad32C[0x10D4 - 0x32C];
    s32 unk_10D4; u8 pad10D8[0x10EC - 0x10D8]; s32 unk_10EC; u8 pad10F0[8]; f32 unk_10F8;
    u8 pad10FC[0x1130 - 0x10FC]; Clock unk_1130; s32 unk_113C; s32 unk_1140;
} Racer;
typedef struct { u8 pad[0x68]; s32 unk_68; } Sound;

extern u8 D_800445F0[];
extern s32 D_8007C1D4;
extern Sound D_800F1AE0;
extern s32 D_800F2728;
extern s32 D_800F2744;
extern s32 D_800F2778;
extern u8 D_800F2AD8[];
void func_800084C0(void *, u8, f32);
s32 func_8001D4B8(Sound *, s32, s32, s32);
void func_8001D640(Sound *, s32, s32);
void func_800764F4(Scene *);
void func_8007A298(Racer *, s32);
void func_8007BBB0(Racer *);
void func_80080E58(Rival *);
void func_80080F08(Rival *);
void func_80080F24(Rival *);
void func_800A04B8(Board *, s32);
void func_800A0F10(s32);
void func_800B9FA4(Racer *, s32, s32, f32, s32, s32);
void func_800BBA2C(Timer *, s32);
void func_800BBB30(Timer *, s32, Pad *);
void func_800BBD78(void *, s32, s32, s32, s32);
void func_800BC07C(PadBuf *, u8);

static inline void clock_reset(Clock *c) {
    c->unk_0 = 0;
    c->unk_8 = 0;
    c->unk_4 = -1.0f;
}

static inline s32 scale(s32 v, s32 k) { return (v * k) >> 15; }

static inline void clear_pad(PadBuf *p) {
    p->unk_0[0] = 0; p->unk_0[1] = 0; p->unk_0[2] = 0; p->unk_0[3] = 0;
    p->unk_0[4] = 0; p->unk_0[5] = 0; p->unk_0[6] = 0; p->unk_0[7] = 0;
}

void func_80078BF0(Racer *r, Msg *msg) {
    s32 dt;
    Scene *scene;
    s32 run;
    s32 late;
    s32 ok;
    Pad *pad;

    dt = (msg->unk_4 - r->unk_10) >> 8;
    r->unk_288->unk_0[3] = 0;
    r->unk_288->unk_0[2] = 0;
    switch (msg->unk_0) {
    case 1:
        break;
    case 2:
        scene = r->unk_4;
        run = 1;
        switch (r->unk_AC) {
        case 4:
        case 13:
            func_800BC07C(r->unk_288, msg->u.pad.unk_1);
            break;
        case 5:
        case 6:
        case 8:
        case 9:
            late = 0;
            if (D_800F2728 == 0 || msg->unk_4 - D_800F2778 < 0) {
                late = 1;
            }
            pad = &msg->u.pad;
            if (late) {
                run = 0;
            } else {
                func_800BC07C(r->unk_288, pad->unk_1);
                ok = 0;
                if (scene->unk_75AB != 5) {
                    ok = r->unk_1AA != 4;
                }
                if (ok && r->unk_2E4 != 0) {
                    func_800BBB30(r->unk_284, msg->unk_4 - D_800F2778, pad);
                }
            }
            break;
        }
        if (run) {
            func_8007A298(r, dt);
        }
        break;
    case 15:
        if (r->unk_1AA == 4) {
            func_800BBA2C(r->unk_284, D_800F2744 - D_800F2778);
            r->unk_284->unk_2 = 0;
        }
        func_8007A298(r, dt);
        break;
    case 26:
        func_8007A298(r, dt);
        if (r->unk_300 == 0 && r->unk_10F8 < r->unk_320->unk_58) {
            r->unk_300 = 1;
            r->unk_320->unk_1BC = 1;
        }
        if (r->unk_30C == 1) {
            r->unk_2FC = 1;
            if (r->unk_320->unk_1B0 != 1) {
                if (r->unk_320->unk_1B4 != 1) {
                    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0x79, 0, 1), scale(D_800F1AE0.unk_68, 0x7FFF));
                    if (r->unk_1AA == 1) {
                        func_800084C0(D_800445F0, r->unk_2DC, 0.6f);
                    }
                }
                func_80080F08(r->unk_320);
            }
        } else if (r->unk_320->unk_1B4 != 1) {
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0x79, 0, 1), scale(D_800F1AE0.unk_68, 0x7FFF));
            func_80080F24(r->unk_320);
            if (r->unk_1AA == 1) {
                func_800084C0(D_800445F0, r->unk_2DC, 0.4f);
            }
        }
        break;
    case 5:
        if (r->unk_308 == 1) {
            func_8007A298(r, dt);
        }
        break;
    case 17:
        switch (msg->u.unk_10) {
        case 0:
            clear_pad(r->unk_288);
            r->unk_AC = 2;
            func_800B9FA4(r, 5, -1, 1.0f, 0, 1);
            func_8007A298(r, dt);
            break;
        case 1:
            r->unk_AC = 15;
            break;
        }
        break;
    case 18:
        r->unk_284->unk_2 = 0;
        func_800BBA2C(r->unk_284, 0x700);
        func_800BBD78(D_800F2AD8, r->unk_1AB, 0, 0, 5);
        clear_pad(r->unk_288);
        func_800B9FA4(r, 5, -1, 1.0f, 0, 1);
        func_8007BBB0(r);
        func_800764F4(r->unk_4);
        func_800A0F10(r->unk_324);
        r->unk_2F0 = 0;
        r->unk_2EC = 0;
        r->unk_10EC = 0;
        clock_reset(&r->unk_1130);
        D_8007C1D4 = 0;
        r->unk_1140 = 1;
        r->unk_113C = 1;
        r->unk_10D4 = 0;
        r->unk_2FC = 0;
        r->unk_300 = 0;
        r->unk_30C = 0;
        r->unk_310 = 0;
        r->unk_AC = 2;
        func_80080E58(r->unk_320);
        func_800A04B8(r->unk_328, r->unk_328->unk_D4);
        break;
    }
    r->unk_10 = msg->unk_4;
}
