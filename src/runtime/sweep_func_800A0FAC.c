extern unsigned char D_80084DC8[];
extern unsigned char D_800F2758[];
extern void func_800A02C0(void *object);
extern void func_800AA658(void *list, void *item);
extern void func_800A03D4(void *object, int mode);
extern void func_800ADE84(void *object, int mode);

void func_800A0FAC(unsigned char *object, int mode)
{
    unsigned char *part = object + 244;

    *(void **)(object + 180) = D_80084DC8;
    func_800A02C0(part);
    if (*(int *)(object + 240) != 0) {
        func_800AA658(D_800F2758, object + 240);
    }
    func_800A03D4(part, 2);
    func_800ADE84(object, mode);
}
