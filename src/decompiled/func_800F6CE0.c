#include "sydney_types.h"

/* Event message handler of an athlete: pad input, start signal, finish and reset messages. */
typedef struct VtEntry {
    s16 offset;
    s16 unk_02;
    void (*func)();
} VtEntry;

typedef struct Watcher {
    u8 unk_00[0xB4];
    VtEntry *vtbl;
} Watcher;

typedef struct Msg {
    s32 type;
    s32 time;
    u8 unk_08[8];
    union {
        s32 i;
        u8 b[4];
    } arg;
} Msg;

typedef struct Anim {
    u8 unk_00[2];
    s16 unk_02;
} Anim;

typedef struct Owner {
    u8 unk_0000[0x1898];
    u8 unk_1898[0x8054 - 0x1898];
    u8 kind;
} Owner;

typedef struct Athlete {
    u8 unk_000[4];
    Owner *owner;
    u8 unk_008[8];
    s32 time;
    u8 unk_014[0xAC - 0x14];
    u32 state;
    u8 unk_0B0[0x1AA - 0xB0];
    u8 unk_1AA;
    s8 unk_1AB;
    u8 unk_1AC[0x278 - 0x1AC];
    f32 animSpeed;
    u8 unk_27C[0x284 - 0x27C];
    Anim *anim;
    u8 *pad;
    u8 unk_28C[0x2EC - 0x28C];
    s32 unk_2EC;
    u8 unk_2F0[4];
    u8 unk_2F4;
    u8 unk_2F5[0x318 - 0x2F5];
    Watcher *watcher;
    u8 unk_31C[0x380 - 0x31C];
    s32 voice;
} Athlete;

typedef struct Snd {
    u8 unk_00[0x68];
    s32 volume;
} Snd;

extern Snd D_800F1AE0;
extern u8 D_800F26E0[];
extern u8 D_800F2AD8[];
extern s32 D_800F2744;
extern volatile s32 D_800F2778;
extern volatile s32 D_800F2728;

void func_800BC07C(u8 *pad, u8 a);
void func_800BBB30(Anim *anim, s32 t, void *arg);
void func_800BBA2C(Anim *anim, s32 t);
void func_80079E88(Athlete *a, s32 dt);
s32 func_8001D4B8(Snd *snd, s32 id, s32 a, s32 b);
void func_8001D640(Snd *snd, s32 voice, s32 vol);
void func_8001D5D8(Snd *snd, s32 voice, s32 vol, s32 a, s32 b, s32 c);
void func_800A6308(void *p);
void func_800AACB0(void *list, void *item, s32 mode);
void func_8007903C(Athlete *a);
void func_800B9FA4(Athlete *a, s32 anim, s32 b, f32 speed, s32 c, s32 d);
s32 func_800B9BD4(Athlete *a, s32 mode, f32 *b, f32 *c, f32 *d, s32 e);
void func_800B9964(Athlete *a, f32 *b, f32 *c, f32 *d);
void func_80076804(Owner *o);
void func_800BBD78(void *list, s32 a, s32 b, s32 c, s32 d);
void func_800B7824(Athlete *a, s32 b);

static __inline__ s32 scaleVol(Snd *snd, s32 v) {
    return (snd->volume * v) >> 15;
}

static __inline__ void clearPad(u8 *pad) {
    pad[0] = 0;
    pad[1] = 0;
    pad[2] = 0;
    pad[3] = 0;
    pad[4] = 0;
    pad[5] = 0;
    pad[6] = 0;
    pad[7] = 0;
}

void func_80078BF0(Athlete *a, Msg *msg) {
    f32 sp18[4];
    f32 sp28[4];
    f32 sp38[2];
    s32 dt;
    Owner *owner;
    s32 voice;
    s32 ok;
    Watcher *w;
    u8 *b;
    Snd *snd;
    Owner *game;

    dt = (msg->time - a->time) >> 8;
    a->pad[3] = 0;
    a->pad[2] = 0;
    switch (msg->type) {
    case 2:
        b = msg->arg.b;
        owner = a->owner;
        func_800BC07C(a->pad, b[1]);
        if (a->state < 7) {
            if (a->state >= 4) {
                ok = 0;
                D_800F2728;
                if (owner->kind != 5) {
                    ok = a->unk_1AA != 4;
                }
                if (ok && a->unk_2EC != 0 && -D_800F2778 + msg->time >= 0) {
                    func_800BBB30(a->anim, msg->time - D_800F2778, b);
                }
            }
        }
        func_80079E88(a, dt);
        break;
    case 15:
        if (a->unk_1AA == 4) {
            func_800BBA2C(a->anim, D_800F2744 - D_800F2778);
            a->anim->unk_02 = 0;
        }
        func_80079E88(a, dt);
        break;
    case 26:
        snd = &D_800F1AE0;
        game = a->owner;
        func_8001D640(snd, func_8001D4B8(snd, 0xB6, 0, 1), scaleVol(snd, 0x7FFF));
        if (game->kind != 4) {
            func_8001D640(snd, func_8001D4B8(snd, 0x72, 0, 1), scaleVol(snd, 0x5998));
            voice = func_8001D4B8(snd, 0x70, 0, -1);
            func_8001D640(snd, voice, 0);
            func_8001D5D8(snd, voice, scaleVol(snd, 0x5FFF), 0x4E, 0, 0);
            a->voice = voice;
            if (a->unk_2F4 == 0) {
                func_800A6308(game->unk_1898);
            }
        }
        if (a->unk_1AA != 4) {
            func_800AACB0(D_800F26E0, game, 0x19);
        }
        a->state = 0xF;
        func_80079E88(a, dt);
        break;
    case 5:
        func_80079E88(a, dt);
        break;
    case 17:
        switch (msg->arg.i) {
        case 0:
            func_8007903C(a);
            func_800B9FA4(a, 9, -1, a->animSpeed, 0, 1);
            clearPad(a->pad);
            a->state = 2;
            func_800B9BD4(a, 1, sp28, sp38, sp18, 0);
            func_800B9964(a, sp28, sp38, sp18);
            func_80079E88(a, dt);
            break;
        case 1:
            a->state = 0x10;
            break;
        }
        break;
    case 18:
        a->anim->unk_02 = 0;
        func_800BBA2C(a->anim, 0x700);
        func_8007903C(a);
        func_80076804(a->owner);
        w = a->watcher;
        w->vtbl[2].func((u8 *)w + w->vtbl[2].offset, a);
        func_800BBD78(D_800F2AD8, a->unk_1AB, 0, 0, 5);
        clearPad(a->pad);
        func_800B7824(a, 0);
        func_800B9FA4(a, 9, -1, a->animSpeed, 0, 1);
        func_800B9BD4(a, 1, sp28, sp38, sp18, 0);
        func_800B9964(a, sp28, sp38, sp18);
        a->state = 2;
        break;
    }
    a->time = msg->time;
}
