extern unsigned char D_80085130[];
extern unsigned char D_800F2758[];
extern void func_800A02C0(void *object);
extern void func_800AA658(void *list, void *item);
extern void func_800A03D4(void *object, int mode);
extern void func_800ADE84(void *object, int mode);

void func_800A2C34(unsigned char *object, int mode)
{
    unsigned char *part = object + 240;

    *(void **)(object + 180) = D_80085130;
    func_800A02C0(part);
    if (*(int *)(object + 236) != 0) {
        func_800AA658(D_800F2758, object + 236);
    }
    func_800A03D4(part, 2);
    func_800ADE84(object, mode);
}
