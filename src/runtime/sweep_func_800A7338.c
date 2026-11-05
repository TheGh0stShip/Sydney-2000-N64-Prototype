extern unsigned char D_80085888[];
extern unsigned char D_800F2758[];
extern void func_800AA658(void *list, void *item);
extern void func_800ADE84(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_800A7338(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80085888;
    if (*(int *)(object + 196) != 0) {
        func_800AA658(D_800F2758, object + 196);
        object[200] = 0;
    }
    func_800ADE84(object + 208, 2);
    func_800AC3A4(object, mode);
}
