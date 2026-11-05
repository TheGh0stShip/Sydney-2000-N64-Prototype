extern unsigned char D_80084C58[];
extern void func_800AC3A4(void *object, int mode);

void func_800A03D4(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084C58;
    func_800AC3A4(object, mode);
}
