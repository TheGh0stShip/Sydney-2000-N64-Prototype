extern void func_800B3870(void *destination, void *source, int size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *definition);
extern void func_800A9B78(void *object, void *value, int mode, void *extra,
                          int state);

void func_800811B8(unsigned char *object, unsigned char *definition, void *extra)
{
    unsigned char *sub;

    func_800B3870(object + 0x8800, definition + 20, 76);
    sub = object + 0x87EC;
    if (*(int *)(sub + 4) != 0) {
        func_800AC334(sub);
    }
    func_800AC37C(sub, definition);
    func_800A9B78(object + 0x86F8, sub, 1, extra, 2);
}
