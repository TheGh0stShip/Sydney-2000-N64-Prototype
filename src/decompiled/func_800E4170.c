#include "sydney_types.h"

/* Per-frame state machine of a scripted athlete: plays its animation sequence and advances its state. */
typedef struct Game {
    u8 unk_00000[0x10B10];
    s32 paused;
} Game;

typedef struct Owner {
    u8 unk_000[4];
    Game *game;
    u8 unk_008[0x310 - 8];
    f32 unk_310;
} Owner;

typedef struct Athlete {
    u8 unk_000[4];
    Owner *owner;
    u8 unk_008[0xAC - 8];
    s32 state;
    u8 unk_0B0[0x194 - 0xB0];
    u8 seqPos;
    u8 unk_195;
    s16 seq[(0x260 - 0x196) / 2];
    f32 speed;
    u8 unk_264[0xABC - 0x264];
    f32 unk_ABC;
    u8 unk_AC0[0xACC - 0xAC0];
    s32 unk_ACC;
    u8 unk_AD0[0xAE0 - 0xAD0];
    s32 unk_AE0;
    u8 unk_AE4[0xB48 - 0xAE4];
    s32 unk_B48;
} Athlete;

extern u8 D_800F26E0[];
extern s32 D_800F2744;

s32 func_800B9BD4(Athlete *a, s32 mode, f32 *b, f32 *c, f32 *d, s32 e);
void func_800B9964(Athlete *a, f32 *b, f32 *c, f32 *d);
s32 func_8007BBE4(Athlete *a);
void func_800B9E74(Athlete *a, s32 b);
void func_80075FC8(Game *g);
void func_800B9E9C(Athlete *a, s32 anim, s32 b, f32 speed, s32 c);
void func_800B9FA4(Athlete *a, s32 anim, s32 b, f32 speed, s32 c, s32 d);
void func_800AB2A4(void *list, s32 a, s32 b, Owner *o, s32 c, s32 d);
void func_800B8C70(Athlete *a, s32 b);
void func_800B7578(Athlete *a, s32 b, s32 c, s32 anim, s32 d, f32 speed, s32 e, s32 f);
void func_800B9CDC(Athlete *a, s32 b, s32 c);
void func_800798C8(Athlete *a);

void func_800794B0(Athlete *a, s32 active) {
    f32 sp20[4];
    f32 sp30[4];
    f32 sp40[2];
    Owner *owner;
    Game *game;
    s16 id;
    u8 n;

    if (active != 1) {
        return;
    }
    owner = a->owner;
    game = owner->game;
    if (game->paused == active) {
        return;
    }
    switch (a->state) {
    case 4:
        if (func_800B9BD4(a, 1, sp20, sp40, sp30, 0) != 0) {
            n = ++a->seqPos;
            id = a->seq[n];
            if (id < 0) {
                if (id != -1) {
                    a->state = 5;
                    break;
                }
                a->seq[n] = -2;
                a->speed = 1.0f;
                id = func_8007BBE4(a);
                func_800B9E74(a, 4);
                a->seqPos--;
                func_80075FC8(game);
            }
            func_800B9E9C(a, id, -1, a->speed, 0);
        }
        func_800B9964(a, sp20, sp40, sp30);
        break;
    case 8:
        if (func_800B9BD4(a, 1, sp20, sp40, sp30, 0) != 0) {
            a->speed = 1.0f;
            func_800B9FA4(a, func_8007BBE4(a), -1, a->speed, 0, 1);
            func_800B9E9C(a, 0xB, -1, a->speed, 0);
            func_800B9E74(a, 2);
            a->state = 5;
        }
        break;
    case 5:
        func_800AB2A4(D_800F26E0, D_800F2744, 0xE, owner, 0, a->unk_B48);
        a->state = 6;
        break;
    case 7:
        a->speed = 1.0f;
        func_800B9FA4(a, 0xB, -1, a->speed, 0, 1);
        func_800B9E9C(a, 0x10, -1, a->speed, 0);
        func_800B9E74(a, 4);
        a->state = 0xA;
        break;
    case 10:
        a->state = 0xC;
        break;
    case 12:
        if (a->unk_ACC == 0) {
            a->unk_ABC = a->owner->unk_310;
            if (a->unk_ABC < 0.03f) {
                a->unk_ABC = 0.03f;
            }
        }
        func_800B8C70(a, a->unk_AE0);
        func_800B9BD4(a, 1, sp20, sp40, sp30, 0);
        break;
    case 11:
        func_800B8C70(a, a->unk_AE0);
        if (func_800B9BD4(a, 1, sp20, sp40, sp30, 0) & 2) {
            func_800B7578(a, 0, 0xB, 0x1A, -1, 1.0f, 0, 0);
            func_800B9CDC(a, 0, 4);
        }
        break;
    case 32:
        func_800B8C70(a, a->unk_AE0);
        if (func_800B9BD4(a, 1, sp20, sp40, sp30, 0) & 2) {
            n = ++a->seqPos;
            id = a->seq[n];
            if (id < 0) {
                if (id != -1) {
                    a->state = 0x21;
                    func_800B9E9C(a, 0x18, -1, a->speed, 0);
                    func_800B9CDC(a, 0, 4);
                    break;
                }
                a->seq[n] = -2;
                func_800B9E74(a, 4);
                id = 0x18;
                a->seqPos--;
            }
            func_800B7578(a, 0, 0xB, id, -1, 1.0f, 0, 0);
            func_800B9CDC(a, 0, 4);
        }
        break;
    case 33:
        func_800B8C70(a, a->unk_AE0);
        /* fallthrough */
    case 9:
        func_800B9BD4(a, 1, sp20, sp40, sp30, 0);
        break;
    }
    func_800798C8(a);
}
