extern void func_800AC3A4(void *object);
extern unsigned char D_800859E0[];

void func_800A86AC(unsigned char *object)
{
    *(void **)(object + 180) = D_800859E0;
    func_800AC3A4(object);
}
