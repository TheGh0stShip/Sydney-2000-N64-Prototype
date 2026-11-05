typedef struct {
    unsigned char pad[0xD4];
} Unk800C6AC0;

extern Unk800C6AC0 D_80101960[8];
extern void func_800ADED4(void *obj);

void func_800C6AC0(void) {
    Unk800C6AC0 *p = D_80101960;
    int i;

    for (i = 7; i != -1; i--) {
        func_800ADED4(p);
        p++;
    }
}
