#include "sydney_types.h"

/* Slider widget update: reads the bound value (int/short/byte), clamps it to its range, updates the end-arrow and pip highlights, and returns the value (or a table lookup of it). */
typedef struct Binding {
    void *ptr;      /* 0x00 */
    s32 type;       /* 0x04 0=s32 1=s16 2=s8 */
    s32 min;        /* 0x08 */
    s32 max;        /* 0x0C */
    u8 pad10[4];
    u16 *table;     /* 0x14 */
} Binding;

typedef struct Def {
    u8 pad00[4];
    u32 flags;      /* 0x04 */
    u8 pad08[0x1C - 8];
    Binding *bind;  /* 0x1C */
} Def;

typedef struct Sprite {
    u8 pad00[0xC0];
    u32 flags;      /* 0xC0 */
    s32 color;      /* 0xC4 */
    u8 padC8;
    u8 unk_C9;      /* 0xC9 */
} Sprite;

typedef struct Pip {
    u8 pad00[0xC0];
    volatile u32 flags; /* 0xC0 */
    s32 color;      /* 0xC4 */
} Pip;

typedef struct Widget {
    u8 pad00[0xDC];
    Def *def;               /* 0x0DC */
    u8 padE0[0x2C8 - 0xE0];
    Sprite *right;          /* 0x2C8 */
    Sprite *left;           /* 0x2CC */
    u8 pad2D0[0x2EC - 0x2D0];
    Pip *pip[5];         /* 0x2EC */
    Pip *pipEnd;            /* 0x300 */
    u8 pad304[0x318 - 0x304];
    Sprite *label;          /* 0x318 */
    u8 pad31C[0x354 - 0x31C];
    u32 style;              /* 0x354 */
} Widget;

extern s32 D_800F40D4[4];
extern void func_800CE468(Sprite *, s32, s32, s32, s32, s32);
extern s32 func_800D98FC(u16);

s32 *func_800C2FE0(Widget *w, s32 *out) {
    u32 flags = w->def->flags;
    Binding *b = w->def->bind;
    Sprite *l;
    Pip *p;
    s32 kind = flags & 0xFFFF;
    u32 locked = flags & 0x4000000;
    s32 v;
    u16 i;

    v = 0;
    switch (b->type) {
    case 0: v = *(s32 *)b->ptr; break;
    case 1: v = *(s16 *)b->ptr; break;
    case 2: v = *(s8 *)b->ptr; break;
    }
    if (v < b->min || v > b->max) {
        if (v > b->max) {
            v = b->max;
        } else {
            v = b->min;
        }
        switch (b->type) {
        case 0: *(s32 *)b->ptr = v; break;
        case 1: *(s16 *)b->ptr = v; break;
        case 2: *(s8 *)b->ptr = v; break;
        }
    }
    if ((w->style & 2) && !locked) {
        if (v == b->max) {
            w->left->flags |= 4;
        } else {
            w->left->flags &= ~4;
        }
        if (v == b->min) {
            w->right->flags |= 4;
        } else {
            w->right->flags &= ~4;
        }
    }
    if (w->style & 4) {
        i = 0;
        if (v < 6) {
            while (1) {
                if (!(i < v)) break;
                p = w->pip[i];
                p->flags;
                p = w->pip[i++];
                p->color = D_800F40D4[0];
            }
            while (1) {
                if (!(i < 5)) break;
                p = w->pip[i];
                p->flags;
                p = w->pip[i++];
                p->color = D_800F40D4[1];
            }
            w->pipEnd->flags;
            w->pipEnd->color = D_800F40D4[3];
        } else if (v == 6) {
            while (1) {
                if (!(i < v)) break;
                p = w->pip[i];
                p->flags;
                p = w->pip[i++];
                p->color = D_800F40D4[1];
            }
            w->pipEnd->flags;
            w->pipEnd->color = D_800F40D4[2];
        }
    }
    if ((w->def->flags & 0x40000) && w->label != NULL) {
        func_800CE468(w->label, 0, v & 0xFF, 0x38, -4, 2);
        l = w->label;
        l->unk_C9 = 3;
        l->flags |= 0x20000;
    }
    if (kind == 11 || kind == 12) {
        *out = func_800D98FC(b->table[v]);
    } else {
        *out = v;
    }
    return out;
}
