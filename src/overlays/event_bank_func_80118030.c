extern unsigned char D_8007E040[];
extern void func_800A6B04(void *object, int mode);
extern void func_800E57A4(void *object, int mode);
extern void func_800A63CC(void *object, int mode);

void func_80118030(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_8007E040;
    func_800A6B04(object + 736, 2);
    func_800E57A4(object + 196, 2);
    func_800A63CC(object, mode);
}
