#include "sydney_types.h"

/* Per-frame update of a two-part event object: grows a timer; once it expires, swaps the active part, resets it and plays a sound. */
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct VEntry { s16 offset; s16 pad; void (*fn)(void *, s32); } VEntry;
typedef struct Motion {
    f32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 pad0C;
    s32 unk_10;
    f32 unk_14;
    s32 unk_18;
    s32 pad1C;
    s32 unk_20;
    s32 unk_24;
    f32 unk_28;
    u8 pad2C[0x14];
    Vec3 unk_40;
} Motion;
typedef struct Part {
    u8 pad00[0x14];
    Motion motion;
    u8 pad60[0x54];
    VEntry *vtable;
    u8 padB8[0xC];
    s32 unk_C4;
    u8 padC8[0xC];
} Part;
typedef struct Entry { s32 unk_00; s32 unk_04; s32 unk_08; } Entry;
typedef struct Obj {
    u8 pad0000[0x43C8];
    Part parts[2];
    f32 timer;
    u8 cur;
    u8 step;
    u8 pad4576[0x1A2];
    s32 unk_4718;
    s32 pad471C;
    s8 *unk_4720;
} Obj;
typedef struct Sound { u8 pad[0x68]; s32 unk_68; } Sound;

extern Entry D_80071A40[];
extern Vec3 D_80071AA0;
extern Sound D_800F1AE0;

s32 func_8001D4B8(Sound *, s32, s32, s32);
void func_8001D640(Sound *, s32, s32);
void func_800AD4E0(Motion *, f32, s32);

static inline s32 scale(s32 v, s32 k) { return (v * k) >> 15; }

static inline void reset(Motion *m) {
    m->unk_24 = 0;
    m->unk_20 = 0;
    m->unk_18 = 0;
    m->unk_10 = 0;
    m->unk_08 = 0;
    m->unk_04 = 0;
    m->unk_40.z = 0;
    m->unk_40.y = 0;
    m->unk_40.x = 0;
    m->unk_28 = 1.0f;
    m->unk_14 = 1.0f;
    m->unk_00 = 1.0f;
    m->unk_40.x = D_80071AA0.x;
    m->unk_40.y = D_80071AA0.y;
    m->unk_40.z = D_80071AA0.z;
}

void func_800D3018(Obj *this) {
    u8 i;

    this->timer += 0.18616843f;
    if (this->timer < 3.1415923f) {
        for (i = 0; i < 2; i++) {
            func_800AD4E0(&this->parts[i].motion, 0.18616843f, 3);
        }
        return;
    }
    if (this->step == this->unk_4718) {
        VEntry *vt = (this->parts + this->cur)->vtable;
        vt[9].fn((u8 *)(this->parts + this->cur) + vt[9].offset, this->step);
    } else {
        this->parts[this->cur].unk_C4 = D_80071A40[this->unk_4720[this->step]].unk_08;
    }
    reset(&this->parts[0].motion);
    reset(&this->parts[1].motion);
    func_800AD4E0(&this->parts[this->cur].motion, 3.1415923f, 3);
    this->step++;
    this->cur = 1 - this->cur;
    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 0xFD, 0, 1), scale(D_800F1AE0.unk_68, 0x7FFF));
}
