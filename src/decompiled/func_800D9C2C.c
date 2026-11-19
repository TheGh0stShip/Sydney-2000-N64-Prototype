#include "sydney_types.h"

/* Resets the 8 slots of the global state from the slot table, assigning each its initial mode and counting the modes. */
typedef struct Info {
    u8 unk_00[8];
    u8 id;
    u8 kind;
    u8 unk_0A;
    u8 unk_0B;
} Info;

typedef struct Blk {
    s32 unk_00, unk_04, unk_08, unk_0C, unk_10;
} Blk;

typedef struct Slot {
    Info info;
    u8 state;
    u8 index;
    u8 pad0E[2];
    s32 unk_10;
    Blk unk_14;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad34[4];
    u8 unk_38;
    u8 pad39[3];
} Slot;

typedef struct G {
    u8 pad000[0x14];
    Slot slots[8];
    s8 order[8];
    u8 unk_1FC;
    u8 unk_1FD;
    u8 unk_1FE;
    u8 unk_1FF;
    u32 mask;
    u8 pad204[0xD70 - 0x204];
    Info infos[8];
} G;

extern G *D_800FC270;
extern Blk D_800FCAF8;
typedef struct Rng {
    s32 seed;
} Rng;

extern Rng D_800F2714;

void func_800D9C2C(s32 flag) {
    u8 i;
    Slot *s;

    D_800FC270->unk_1FC = 0;
    D_800FC270->unk_1FD = 0;
    D_800FC270->unk_1FF = 6;
    s = D_800FC270->slots;
    i = 0;
    while (1) {
        if (i >= 8) {
            break;
        }
        if (D_800FC270->order[i] != -1) {
        s->info = D_800FC270->infos[i];
        s->index = i;
        s->unk_14 = D_800FCAF8;
        s->unk_10 = 0;
        s->unk_28 = 0;
        s->unk_2C = 0;
        s->unk_30 = 0;
        D_800F2714.seed = (D_800F2714.seed * 16807) & 0x7FFFFFFF;
        s->info.unk_0A = 0;
        D_800FC270->mask |= 1 << s->info.id;
        if (D_800FC270->infos[i].kind == 6 && flag == 0) {
            s->unk_38 = i + 13;
            s->state = 2;
            D_800FC270->unk_1FD++;
        } else {
            if (flag != 0) {
                s->info.kind = 1;
                D_800FC270->unk_1FF = 1;
            } else if (D_800FC270->infos[i].kind < D_800FC270->unk_1FF) {
                D_800FC270->unk_1FF = D_800FC270->infos[i].kind;
            }
            s->unk_38 = D_800FC270->order[i];
            s->state = 1;
            D_800FC270->unk_1FC++;
        }
        } else {
            s->state = 0;
        }
        s++;
        i++;
    }
}
