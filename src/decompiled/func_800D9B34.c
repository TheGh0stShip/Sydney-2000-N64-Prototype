#include "sydney_types.h"

/* Fills the current event's descriptor from a 12-byte template, resets its state and advances the event count. */
typedef struct { u8 unk_00[8]; u8 unk_08; u8 unk_09; u8 unk_0A; u8 unk_0B; } Template; /* byte-aligned */
typedef struct { s32 unk_00[5]; } Block;
typedef struct {
    Template tmpl;  /* 0x00 */
    u8 unk_0C;
    u8 unk_0D;
    u8 pad0E[2];
    s32 unk_10;
    Block unk_14;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad34[4];
    u8 unk_38;
} Desc;
typedef struct {
    u8 pad00[0x14];
    Desc desc;      /* 0x14 */
    u8 pad[0x1F4 - 0x14 - sizeof(Desc)];
    u8 unk_1F4;
    u8 pad1F5[7];
    u8 unk_1FC;
    u8 pad1FD[3];
    s32 unk_200;
} Game;
extern Game *D_800FC270;
extern Block D_800FCAF8;
extern s32 D_800F2714[];
void func_800D9B34(Template *t) {
    Desc *d = &D_800FC270->desc;
    d->unk_38 = D_800FC270->unk_1F4;
    d->tmpl = *t;
    d->unk_0C = 1;
    d->unk_0D = D_800FC270->unk_1FC;
    d->unk_10 = 0;
    d->unk_14 = D_800FCAF8;
    d->unk_28 = 0;
    d->unk_2C = 0;
    d->unk_30 = 0;
    D_800F2714[0] = (D_800F2714[0] * 16807) & 0x7FFFFFFF;
    d->tmpl.unk_0A = 0;
    D_800FC270->unk_200 = 1 << d->tmpl.unk_08;
    D_800FC270->unk_1FC++;
}
