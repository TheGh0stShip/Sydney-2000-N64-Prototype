typedef struct {
    char pad[6];
    unsigned short unk6;
} Item;

typedef struct {
    Item *item;
    int data;
} Entry;

typedef struct {
    Entry *entries;
    unsigned char count;
} List;

extern char D_800F2758[];
extern void func_800AA658(void *dst, void *src);

void func_800AA068(List *list) {
    unsigned char i;
    char *dst = D_800F2758;

    for (i = 0; i < list->count; i++) {
        if (list->entries[i].item->unk6 != 0) {
            func_800AA658(dst, &list->entries[i].data);
        }
    }
    func_800AA658(dst, list);
}
