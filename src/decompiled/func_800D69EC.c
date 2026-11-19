#include "sydney_types.h"

/* Reports an event for the object in arg->unk_04 when the global flag bits are set; returns -1. */
typedef struct { u8 unk_00[0x10]; u16 unk_10; } Info;
typedef struct { u8 unk_00[0xD68]; s32 unk_D68; } State;
typedef struct { s32 unk_00; s32 unk_04; } Arg;
extern State *D_800FC270;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
Info *func_800DCCF4(s32);
void func_800AB2A4(void *, s32, s32, s32, s32, s32);

s32 func_800D69EC(Arg *arg0) {
    s32 id;
    Info *info;

    if (D_800FC270->unk_D68 & 0xFFF) {
        id = arg0->unk_04;
        info = func_800DCCF4(id);
        func_800AB2A4(D_800F26E0, D_800F2744, 10, id, 0, info->unk_10);
    }
    return -1;
}
