#include "sydney_types.h"

/* When active: copies an 8-byte header, rebuilds an entry list from the source table and submits it, then advances counters. */
typedef struct Header {
    u8 b[8];
} Header;

typedef struct Ent {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} Ent;

typedef struct Src {
    s32 unk_00;
    s32 unk_04;
} Src;

typedef struct Obj {
    u8 pad00[0xCE];
    u8 unk_CE;
    u8 unk_CF;
    u8 unk_D0;
    u8 padD1[3];
    s32 unk_D4;
    u8 padD8[0x10];
    Header unk_E8;
    Ent ents[14];
    Src src[20];
    u16 unk_2E0;
} Obj;

extern u8 D_800F1B84[];
void func_800BFB94(Obj *obj, u16 arg);
void func_8001DC3C(u8 *dst, Ent *ents, s32 count, s32 arg3, s32 arg4, s32 arg5);

void func_800BFFDC(Obj *obj, s32 arg1, Header *hdr, s32 arg3, s32 arg4) {
    u8 count;
    u32 i;

    count = 0;
    if (obj->unk_CE != 0) {
        obj->unk_E8 = *hdr;
        obj->unk_2E0 = 0;
        func_800BFB94(obj, arg1);
        for (i = 0; i < obj->unk_2E0; i++) {
            obj->ents[count].unk_04 = 0;
            obj->ents[count].unk_0C = 0;
            obj->ents[count].unk_08 = 0;
            obj->ents[count].unk_14 = 0;
            obj->ents[count++].unk_00 = obj->src[i].unk_00;
        }
        if (obj->unk_D4 != 1) {
            func_8001DC3C(D_800F1B84, obj->ents, count, arg3, arg4, 0);
        }
        obj->unk_D4 = 0;
        if (++obj->unk_D0 == 5) {
            obj->unk_D0 = 0;
        }
        obj->unk_CF++;
    }
}
