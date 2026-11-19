#include "sydney_types.h"

/* Remove a player's actor from the race: release its sound, unlink it from slot lists, pick a new focus and clear its state. */
typedef struct { u8 pad[0x1AA]; u8 unk_1AA; u8 pad1AB[0x2DD - 0x1AB]; u8 unk_2DD; } Actor;
typedef struct { s16 unk_0; s16 unk_2; u8 pad[8]; } Cell;
typedef struct { u8 pad[0xA10]; Cell cells[1]; } Game;
typedef struct { u8 pad[2]; s16 unk_2; u8 pad4[0x20]; } PState;
typedef struct {
    u8 pad[0x43C];
    Actor *order[8];
    u8 pad45C[0x60C - 0x45C];
    u8 focus;
    u8 nOrder;
    u8 unk_60E;
    u8 pad60F[2];
    u8 base;
    u8 pad612;
    u8 unk_613;
    u8 pad614[0x4120 - 0x614];
    Actor *actors[8];
    u8 pad4140[0x5310 - 0x4140];
    PState ps[8];
    u8 pad5430[0x5470 - 0x5310 - 8 * 0x24];
    u8 unk_5470;
    u8 unk_5471;
} Race;
extern u8 D_800F2AD8[];
extern u8 D_80077730;
extern Game *D_800FC270;
void func_800BBD78(void *, u8, s32, void *, s32);
void func_80076680(Race *, Actor *, s32);
void func_80074920(Race *, u8);
void func_80085EB4(Race *r, u8 player) {
    u8 idx = player - r->base;
    Actor *a = r->actors[idx];
    u8 j;
    Cell *row;
    u8 k;
    if (a == NULL) return;
    func_800BBD78(D_800F2AD8, a->unk_2DD, 0, NULL, 5);
    if (a->unk_1AA == 1) {
        r->unk_5470--;
        func_800BBD78(D_800F2AD8, a->unk_2DD, 1, r, 2);
    } else {
        if (a->unk_1AA == 2) r->unk_5471--;
        func_800BBD78(D_800F2AD8, a->unk_2DD, 1, NULL, 2);
    }
    for (j = 0; j < 8; j++) {
        if (r->order[j] == a) {
            r->order[j] = NULL;
            r->nOrder--;
        }
        if (r->order[j] == NULL && j < 7) {
            r->order[j] = r->order[j + 1];
            r->order[j + 1] = NULL;
        }
    }
    if (r->focus == idx) {
        for (k = 0; k < 8; k++) {
            if (k != r->focus && r->actors[k] != NULL) {
                r->focus = k;
                func_80076680(r, r->actors[r->focus], 1);
                break;
            }
        }
    }
    func_80074920(r, idx);
    { s32 one; s32 p = player; one = 1; r->ps[p].unk_2 = one; D_80077730 &= ~(one << p); }
    row = &D_800FC270->cells[r->unk_60E * r->unk_613];
    row[idx].unk_2 = -1;
}
