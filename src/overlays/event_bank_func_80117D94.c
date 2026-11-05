extern void func_8008DC58(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800A63CC(void *object, int flags);
extern char D_8007E1E0[];

void func_80117D94(unsigned char *object, int flags)
{
    *(void **)(object + 180) = D_8007E1E0;
    func_8008DC58(object + 1436, 2);
    func_8008DC58(object + 956, 2);
    func_800ADE84(object + 740, 2);
    func_800ADE84(object + 480, 2);
    func_800A63CC(object, flags);
}
