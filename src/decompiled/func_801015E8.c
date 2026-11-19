#include "sydney_types.h"

/* Plays the sound effects selected by the object's flags at its scaled position, some picked at random. */
typedef struct { f32 x, y, z; } Vec3;
typedef struct { u8 unk_00[0x68]; s32 volume; } SndBank;
typedef struct { u8 unk_00[0x40]; Vec3 pos; } Body;
typedef struct Obj { u8 unk_000[0x14]; Body body; u8 unk_060[0x164 - 0x60]; s32 flags; } Obj;
extern SndBank D_800F1AE0;
extern u32 D_800F2714;
void func_800A2D00(SndBank *bank, s32 id, Vec3 *pos, f32 pitch, s32 vol, s32 pan);
static inline u32 rand_next(void) {
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return D_800F2714;
}
static inline void play(s32 id, Vec3 *pos, s32 scale) {
    func_800A2D00(&D_800F1AE0, id, pos, 1.0f, (D_800F1AE0.volume * scale) >> 15, 0);
}
void func_801015E8(Obj *o) {
    Vec3 p;
    Vec3 *pp = &p;
    Body *b = &o->body;
    pp->x = b->pos.x;
    pp->y = b->pos.y;
    pp->z = b->pos.z;
    p.x = p.x * 0.5f / 32.767f;
    p.y = p.y * 0.5f / 32.767f;
    p.z = p.z * 0.5f / 32.767f;
    if (o->flags & 3)
        play(0xE7, pp, 0x6665);
    if (o->flags & 8)
        play((rand_next() >> 30) | 0x6A, pp, 0x7FFF);
    if (o->flags & 0x10)
        play((rand_next() >> 29) + 0xA5, pp, 0x7FFF);
    if (o->flags & 4)
        play((rand_next() >> 30) + 0xA9, pp, 0x7FFF);
}
