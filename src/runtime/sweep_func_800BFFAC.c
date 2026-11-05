extern unsigned char D_800F3BC0[];
extern unsigned char D_80088210[];
extern void func_800AC3A4(void *object, int mode);
void func_800BFFAC(void)
{
    unsigned char *object = D_800F3BC0;
    void *m = D_80088210;
    *(void **)(object + 180) = m;
    func_800AC3A4(object, 2);
}
