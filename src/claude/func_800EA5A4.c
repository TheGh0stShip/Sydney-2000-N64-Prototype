typedef struct Unk800EA5A4 {
    int type;
    int unk4;
    int unk8;
    struct Unk800EA5A4 *next;
} Unk800EA5A4;

extern Unk800EA5A4 *D_800FFD38;
extern void func_80016120(Unk800EA5A4 *node);

void func_800EA5A4(void) {
    Unk800EA5A4 *node = D_800FFD38;
    int type = 0x3A;

loop:
    if (node != 0) {
        if (node->type == type) {
            func_80016120(node);
        }
        node = node->next;
        goto loop;
    }
}
