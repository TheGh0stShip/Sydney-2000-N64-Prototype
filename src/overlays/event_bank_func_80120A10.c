typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Item {
    char pad00[0xB4];
    VEntry *vtable;
} Item;

typedef struct Inventory {
    char pad000[0xB4];
    VEntry *vtable;
    char pad0B8[0xD4 - 0xB8];
    Item *cursor;
    Item *items[11];
    char list[1];
} Inventory;

extern VEntry D_80080A58[];
extern char D_800F2758[];

extern void func_800A02C0(void *list);
extern void func_800A03D4(void *list, int flags);
extern void func_800AA658(void *pool, Item **slot);
extern void func_800AC3A4(Inventory *inv, int flags);

void func_80120A10(Inventory *inv, int flags) {
    int i;

    inv->vtable = D_80080A58;
    func_800A02C0(inv->list);
    for (i = 0; i < 11; i++) {
        if (inv->items[i] != 0) {
            Item *item = inv->items[i];
            item->vtable[1].fn((char *)item + item->vtable[1].delta, 2);
            func_800AA658(D_800F2758, &inv->items[i]);
        }
    }
    if (inv->cursor != 0) {
        func_800AA658(D_800F2758, &inv->cursor);
    }
    func_800A03D4(inv->list, 2);
    func_800AC3A4(inv, flags);
}
