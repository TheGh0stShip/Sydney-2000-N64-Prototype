extern unsigned char D_8007E040[];
extern void func_800A63CC(void *object, int mode);

void func_80119040(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_8007E040;
    func_800A63CC(object, mode);
}
