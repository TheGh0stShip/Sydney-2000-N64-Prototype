#include "sydney_types.h"

/* Refreshes the highlight flag (bit 2) of option widgets from the bound variable's current value. */
typedef struct {
    u8 pad0[0xC0];
    s32 flags;
} Widget;
typedef struct {
    void *ptr;
    s32 type;
    s32 unk_8;
    s32 unk_C;
} Var;
typedef struct {
    u8 pad0[4];
    s32 unk_4;
    u8 pad8[0x1C - 8];
    Var *unk_1C;
} Item;
typedef struct Menu {
    u8 pad0[0xDC];
    Item *unk_DC;
    u8 padE0[0x2C8 - 0xE0];
    Widget *unk_2C8;
    Widget *unk_2CC;
    Widget *unk_2D0;
} Menu;
extern void func_800C3D20(Menu *);
void func_800C19DC(Menu *menu) {
    Item *item = menu->unk_DC;
    s32 flags = item->unk_4;
    u32 kind = flags & 0xFFFF;
    Var *var;
    s32 locked;
    s32 value;

    if (flags & 0x80000) {
        func_800C3D20(menu);
        return;
    }
    var = item->unk_1C;
    locked = flags & 0x4000000;
    switch (kind) {
    case 10:
    case 11:
    case 12: {
        menu->unk_2CC->flags &= ~4;
        menu->unk_2C8->flags &= ~4;
        switch (var->type) {
        case 0:
            value = *(s32 *)var->ptr;
            break;
        case 1:
            value = *(s16 *)var->ptr;
            break;
        case 2:
            value = *(s8 *)var->ptr;
            break;
        }
        if (!locked) {
            if (value == var->unk_C) {
                menu->unk_2CC->flags |= 4;
            } else {
                menu->unk_2CC->flags &= ~4;
            }
            if (value == var->unk_8) {
                menu->unk_2C8->flags |= 4;
            } else {
                menu->unk_2C8->flags &= ~4;
            }
        }
        break;
    }
    case 27: {
        menu->unk_2D0->flags &= ~4;
        menu->unk_2CC->flags &= ~4;
        switch (var->type) {
        case 0:
            value = *(s32 *)var->ptr;
            break;
        case 1:
            value = *(s16 *)var->ptr;
            break;
        case 2:
            value = *(s8 *)var->ptr;
            break;
        }
        if (!locked) {
            if (value == var->unk_C) {
                menu->unk_2D0->flags |= 4;
            } else {
                menu->unk_2D0->flags &= ~4;
            }
            if (value == var->unk_8) {
                menu->unk_2CC->flags |= 4;
            } else {
                menu->unk_2C8->flags &= ~4;
            }
        }
        break;
    }
    }
}
