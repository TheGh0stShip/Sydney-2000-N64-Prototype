#include "sydney_types.h"

/* Computes how far the actor has risen relative to its base height and picks the next state from it. */
typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 unk_00; f32 limit; s32 unk_08; } Level;
typedef struct { u8 pad[0xA10]; Level levels[1]; } Game;
typedef struct { u8 pad[0x7CAD]; u8 level; } Ctx;
typedef struct {
    u8 pad00[4];
    Ctx *ctx;
    u8 pad08[0x5C - 8];
    f32 baseZ;
    u8 pad60[0xAC - 0x60];
    s32 unk_AC;
    u8 padB0[0x2E4 - 0xB0];
    u8 unk_2E4;
    u8 pad2E5[0x304 - 0x2E5];
    Vec3 pos;
    u8 pad310[0x320 - 0x310];
    s32 unk_320;
    u8 pad324[0x34C - 0x324];
    f32 height;
} Actor;
extern Game *D_800FC270;
extern f32 D_80078B94;
void func_8007B0EC(Actor *a, s32 state);
static inline void vecCopy(Vec3 *d, Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
void func_8010807C(Actor *a) {
    Vec3 pos;
    Level *lv;
    a->unk_320 = 0;
    lv = &D_800FC270->levels[a->ctx->level];
    vecCopy(&pos, &a->pos);
    a->height = (pos.z - a->baseZ) / D_80078B94;
    if (a->unk_2E4) {
        func_8007B0EC(a, 4);
        return;
    }
    if (lv->limit <= a->height) {
        func_8007B0EC(a, 6);
    } else {
        func_8007B0EC(a, 5);
    }
    a->unk_AC = 25;
}
