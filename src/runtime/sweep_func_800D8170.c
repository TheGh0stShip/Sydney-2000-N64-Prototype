extern unsigned char D_8008A6C8;
extern void func_800AC3A4(void *object);

void func_800D8170(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008A6C8;
    func_800AC3A4(object);
}
