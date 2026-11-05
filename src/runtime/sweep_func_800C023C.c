extern unsigned char D_800F1B84[];
extern unsigned char D_800F1AE0[];
extern void func_800C02B4(void *object);
extern void func_8001E058(void *list);
extern void func_800A3054(void *list, void (*callback)(void *));
extern int func_800BF540(void *object);

int func_800C023C(unsigned char *object, unsigned int mode)
{
    int result;

    func_8001E058(D_800F1B84);
    func_800A3054(D_800F1AE0, func_800C02B4);
    if (mode >= 13) {
        return 0;
    }
    *(unsigned int *)(object + 220) = mode;
    result = func_800BF540(object);
    object[206] = 1;
    return result;
}
