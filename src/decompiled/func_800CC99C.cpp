#include "sydney_types.h"

/* Start (or, for a negative speed, stop) an animation-driven action and play sound 0xCB. */
struct Clip { u8 pad[0xC]; s32 unk_C; };
struct Anim { s32 unk_0; s32 unk_4; s32 unk_8; f32 unk_C; f32 unk_10; };
struct Snd { u8 pad[0x68]; s32 unk_68; };
extern "C" {
Clip *func_8001A154(Anim *);
Clip *func_8001A148(Anim *);
void func_8001A188(Anim *, f32, s32);
void func_8001A1B0(Anim *, f32, s32);
s32 func_8001D4B8(Snd *, s32, s32, s32);
void func_8001D640(Snd *, s32, s32);
extern Snd D_800F1AE0;
}
struct Base {
    s32 unk_00;
    struct Other *unk_04;
    u8 pad08[0xAC];
    virtual void v0() __asm__("func_80000010");
    virtual void v1() __asm__("func_80000014");
    virtual void v2() __asm__("func_80000018");
    virtual void v3() __asm__("func_8000001C");
    virtual void v4() __asm__("func_80000020");
    virtual void v5() __asm__("func_80000024");
    virtual void v6() __asm__("func_80000028");
    virtual void v7() __asm__("func_8000002C");
    virtual void v8() __asm__("func_80000030");
};
struct Pad { u8 pad[0xD4]; };
struct Other : Pad, Base { virtual void v8() __asm__("func_80000034"); };
struct Obj : Base {
    u8 padB8[0x1C];
    Anim unk_D4;
    u8 padE8[0x1B4 - 0xE8];
    s32 unk_1B4;
    u8 pad1B8[0xC];
    u8 unk_1C4;
    f32 unk_1C8;
    f32 unk_1CC;
    f32 unk_1D0;
    s32 unk_1D4;
    void stop() __asm__("func_80014480");
    void start(f32 speed);
};
void Obj::start(f32 speed) {
    Clip *a, *b;
    s32 vol = 0x147;
    s32 id;
    if (speed < 0.0f) {
        unk_1B4 = unk_D4.unk_8;
        stop();
        return;
    }
    a = func_8001A154(&unk_D4);
    b = func_8001A148(&unk_D4);
    unk_04->v8();
    v7();
    unk_D4.unk_C = 0.0f;
    unk_1C4 = 0;
    unk_D4.unk_10 = 0.0f;
    unk_1D0 = 0.0f;
    unk_1C8 = 0.0f;
    unk_1B4 = unk_D4.unk_4;
    unk_1CC = speed * 2.0f;
    func_8001A188(&unk_D4, unk_D4.unk_C, a->unk_C);
    func_8001A1B0(&unk_D4, unk_D4.unk_10, b->unk_C);
    id = func_8001D4B8(&D_800F1AE0, 0xCB, 0, -1);
    func_8001D640(&D_800F1AE0, id, (D_800F1AE0.unk_68 * vol) >> 15);
    unk_1D4 = id;
}
