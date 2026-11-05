extern unsigned char D_800F11A0[];
extern unsigned char D_80084218[];
extern void func_800AC3A4(void *object, int mode);

void func_80096368(void)
{
    unsigned char *object = D_800F11A0;

    *(void **)(object + 180) = D_80084218;
    func_800AC3A4(object, 2);
}
