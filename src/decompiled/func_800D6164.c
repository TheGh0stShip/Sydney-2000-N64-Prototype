#include "sydney_types.h"

/* Picks a target from the object's list according to the message's mode (callback, highest score, random alive, random with/without flag), then applies it. */
typedef struct Target { u8 pad00[0x5C]; f32 score; u8 pad60[0x14A]; u8 unk_1AA; } Target;
typedef struct Obj {
    u8 pad000[0x60C];
    u8 sel;
    u8 pad60D[6];
    u8 count;
    u8 pad614[0x48C8];
    Target *targets[1];
} Obj;
typedef struct Msg { u8 pad[0x10]; u32 mode; } Msg;

extern u32 D_800F2714;

void func_80076334(Obj *, Target *, s32);
u8 func_80076940(Obj *);

static inline u32 rand_below(u32 n) {
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}

void func_800715F4(Obj *this, Msg *msg) {
    f32 best;
    u8 i;
    u32 n;
    s8 off;
    Target *t;

    switch (msg->mode) {
    case 1:
        this->sel = func_80076940(this);
        func_80076334(this, this->targets[this->sel], 1);
        break;
    case 2:
        best = -32766.998046875f;
        n = this->count;
        this->sel = 0;
        i = 0;
        while (1) {
            if (i >= n) {
                break;
            }
            t = this->targets[i];
            if (t != NULL) {
                f32 score = t->score;
                if (best < score) {
                    this->sel = i;
                    best = score;
                }
            }
            i++;
        }
        func_80076334(this, this->targets[this->sel], 1);
        break;
    case 4:
        this->sel = rand_below(this->count);
        off = 0;
        while (this->targets[this->sel] == NULL) {
            this->sel++;
            if (this->sel >= this->count) {
                this->sel = 0;
            }
        }
        off = 0;
        while (1) {
            if (this->targets[this->sel + off]->unk_1AA == 1) {
                break;
            }
            do {
                off++;
                if (this->sel + off >= this->count) {
                    off = -this->sel;
                }
                if (off == 0) {
                    goto done;
                }
            } while (this->targets[this->sel + off] == NULL);
        }
    done:
        this->sel += off;
        func_80076334(this, this->targets[this->sel], 1);
        break;
    case 5:
        this->sel = rand_below(this->count);
        off = 0;
        while (this->targets[this->sel] == NULL) {
            this->sel++;
            if (this->sel >= this->count) {
                this->sel = 0;
            }
        }
        off = 0;
        while (1) {
            if (this->targets[this->sel + off]->unk_1AA != 1) {
                break;
            }
            do {
                off++;
                if (this->sel + off >= this->count) {
                    off = -this->sel;
                }
                if (off == 0) {
                    goto done5;
                }
            } while (this->targets[this->sel + off] == NULL);
        }
    done5:
        this->sel += off;
        func_80076334(this, this->targets[this->sel], 1);
        break;
    }
}
