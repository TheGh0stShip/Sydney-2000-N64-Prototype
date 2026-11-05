typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Unk800D9938;

extern void *D_800FAFC4;
extern int D_800FAFD4;
extern Unk800D9938 D_800F7574[0x3A5];
extern void func_800AA658(void *heap, void **handle);

void func_800D9938(void *heap) {
    unsigned int i;

    if (D_800FAFC4 != 0) {
        func_800AA658(heap, &D_800FAFC4);
    }
    for (i = 0; i < 0x3A5; i++) {
        D_800F7574[i].unkC = 0;
    }
    D_800FAFD4 = -1;
}
