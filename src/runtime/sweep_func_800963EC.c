extern unsigned char D_80084218[];
extern void func_800AC3A4(void *object, int mode);

void func_800963EC(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084218;
    func_800AC3A4(object, mode);
}
