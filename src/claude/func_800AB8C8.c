typedef struct {
    char pad0[0xB1];
    signed char unkB1;
} Item800AB8C8;

typedef struct Node800AB8C8 {
    Item800AB8C8 *item;
    struct Node800AB8C8 *next;
} Node800AB8C8;

typedef struct {
    char pad0[0x14];
    Node800AB8C8 *unk14;
    int unk18;
} Obj800AB8C8;

extern void func_800AB81C(Obj800AB8C8 *obj, Item800AB8C8 *item);
extern void func_800AB580(Obj800AB8C8 *obj);
extern int D_800F2744;

void func_800AB8C8(Obj800AB8C8 *obj) {
    Node800AB8C8 *node;

    for (node = obj->unk14; ({ node != 0; }); node = node->next) {
        if (node->item->unkB1) {
            func_800AB81C(obj, node->item);
        }
    }
    func_800AB580(obj);
    obj->unk18 = D_800F2744;
}
