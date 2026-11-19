#include "sydney_types.h"

/* Message handler: on flag 0x10 play a sound (and maybe update a linked object), else forward the message. */
typedef struct Snd {
    u8 pad[0x68];
    s32 vol;
} Snd;

typedef struct Class12E8 {
    u8 pad00[0x04];
    s32 flags;
    u8 pad08[0x1C - 0x08];
    union {
        u16 (*getValue)(void *self);
        struct {
            u16 unk_1C;
            u16 value;
        } v;
    } u;
} Class12E8;

typedef struct Obj12E8 {
    u8 pad00[0x04];
    void *unk_04;
    u8 pad08[0xDC - 0x08];
    Class12E8 *cls;
} Obj12E8;

typedef struct Linked12E8 {
    u8 pad00[0x12];
    u16 unk_12;
} Linked12E8;

extern Snd D_800F1AE0;

static inline s32 scaleVolume(s32 v, s32 m) {
    return (v * m) >> 15;
}
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern Linked12E8 *func_800DCCF4(void *p);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_800B1550(void *, s32);

void func_800B12E8(Obj12E8 *obj, u8 *msg) {
    s32 h;
    void *target;
    Linked12E8 *linked;

    if (msg[3] & 0x10) {
        if (obj->cls->flags & 0x80000) {
            h = func_8001D4B8(&D_800F1AE0, 0x59, 0, 1);
            func_8001D640(&D_800F1AE0, h, scaleVolume(D_800F1AE0.vol, 0x7FFF));
        } else {
            h = func_8001D4B8(&D_800F1AE0, 0x82, 0, 1);
            func_8001D640(&D_800F1AE0, h, scaleVolume(D_800F1AE0.vol, 0x7FFF));
            target = obj->unk_04;
            linked = func_800DCCF4(target);
            if (obj->cls->flags & 0x100000) {
                linked->unk_12 = obj->cls->u.getValue(obj);
            } else {
                linked->unk_12 = obj->cls->u.v.value;
            }
            func_800AB2A4(D_800F26E0, D_800F2744, 7, target, 0, 0);
        }
    } else {
        func_800B1550(obj, msg[0]);
    }
}
