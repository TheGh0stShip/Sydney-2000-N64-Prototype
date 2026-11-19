#include "sydney_types.h"

/* Remove every heap entry matching (key, owner) (0 = any), returning nodes to the free pool, then re-heapify. */
typedef struct Node { s32 unk_0; s32 unk_4; s32 unk_8; s32 unk_C; s32 unk_10; u16 unk_14; } Node;
typedef struct {
    Node **unk_0;
    Node **items;
    Node **pool;
    u16 count;
    u16 cap;
    u16 nfree;
} Heap;
extern char D_80085CB4[], D_80085CC4[], D_80085CF0[], D_80085D00[];
void func_8001C3B8(char *, char *, s32);
void func_800AAED0(Heap *, u16);
static inline void heap_take(Heap *h, u16 i) {
    h->pool[--h->nfree] = h->items[i];
    h->items[i] = h->items[h->count];
    h->items[i]->unk_14 = i;
    h->count--;
}
void func_800AACB0(Heap *h, s32 key, s32 owner) {
    u16 i;
    if (h->items == NULL) func_8001C3B8(D_80085CB4, D_80085CC4, 0x114);
    if (h->unk_0 == NULL) func_8001C3B8(D_80085CF0, D_80085CC4, 0x115);
    if (h->pool == NULL) func_8001C3B8(D_80085D00, D_80085CC4, 0x116);
    if (h->count == 0 || h->count > h->cap) return;
    for (i = h->count; i != 0; i--) {
        if (h->count == 0) break;
        if (key == 0 || h->items[i]->unk_8 == key || h->items[i]->unk_C == key) {
            if (owner == 0) {
                heap_take(h, i);
            } else if (h->items[i]->unk_0 == owner) {
                heap_take(h, i);
            }
        }
    }
    for (i = h->count >> 1; i != 0; i--) func_800AAED0(h, i);
}
