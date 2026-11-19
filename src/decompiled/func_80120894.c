#include "sydney_types.h"

/* Tries each of 11 table entries with func_800BD638; returns 1 on the first hit. */
typedef struct { u8 pad0[8]; void *unk_8; } Sub;
typedef struct Obj {
    u8 pad0[0xD0];
    Sub *unk_D0;
    u8 padD4[0xA40 - 0xD4];
    u8 unk_A40[1];
} Obj;
typedef struct { u8 unk_0[0x30]; } EntryA;
typedef struct { u8 unk_0[0xC]; } EntryB;
extern s32 func_800BD638(void *, void *, void *, s32, void *, void *);
extern EntryA D_80081C0C[];
extern EntryB D_80081E1C[];
s32 func_80120894(void *arg0, Obj *obj) {
    u8 buf[0x28];
    u32 i;

    for (i = 0; ({ i < 11; }); i++) {
        if (func_800BD638(obj->unk_D0->unk_8, obj->unk_A40, &D_80081C0C[i], 4, &D_80081E1C[i], buf) != 0) {
            return 1;
        }
    }
    return 0;
}
