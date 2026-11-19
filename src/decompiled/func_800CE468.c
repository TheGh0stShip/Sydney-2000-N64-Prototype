#include "sydney_types.h"

/* Builds a model handle from two table lookups, attaches it to the object and sets its position. */
typedef struct {
    u8 unk_00[0x40];
    f32 unk_40;
    f32 unk_44;
    s32 unk_48;
    u8 unk_4C[4];
} Pos;

typedef struct {
    u8 unk_00[0x60];
    Pos unk_60;
    u8 unk_B0;
    u8 unk_B1[0xF];
    s32 unk_C0;
    void *unk_C4;
    u8 unk_C8;
    u8 unk_C9;
} Obj;

extern void *D_800F4920[];
extern void *D_800F6400[];
extern void func_80019488(void **, void *);
extern void func_8001A210(void **, s32, s32, f32, f32, s32);
extern void func_8001A160(void **, s32);
extern void func_800ADC54(Obj *, s32);

void func_800CE468(Obj *arg0, u8 arg1, u8 arg2, s16 arg3, s16 arg4, s32 arg5) {
    void *handle;
    Pos *pos;

    handle = D_800F4920[arg1];
    func_80019488(&handle, D_800F6400[arg2]);
    func_8001A210(&handle, 0, 0, 1.0f, 1.0f, 0);
    func_8001A160(&handle, 0x20);
    arg0->unk_C9 = 3;
    arg0->unk_C0 |= 0x20000;
    func_800ADC54(arg0, arg5);
    arg0->unk_C0 |= 2;
    arg0->unk_C4 = handle;
    arg0->unk_B0 = 1;
    pos = &arg0->unk_60;
    pos->unk_40 = arg3;
    pos->unk_44 = arg4;
    pos->unk_48 = 0;
}
