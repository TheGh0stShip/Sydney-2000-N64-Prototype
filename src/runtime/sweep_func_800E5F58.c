extern unsigned char D_800F2758[];
extern void func_800AA658(void *list, void *item);

void func_800E5F58(unsigned char *object)
{
    void *list = D_800F2758;

    *(int *)(object + 220) = 0;
    func_800AA658(list, object + 224);
    func_800AA658(list, object + 228);
    if (*(int *)(object + 252) != 0) {
        func_800AA658(list, object + 236);
    }
    *(int *)(object + 244) = 0;
    *(int *)(object + 240) = 0;
}
