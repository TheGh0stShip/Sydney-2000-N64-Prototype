extern unsigned char D_80078C30[];
extern unsigned char D_80078CA0[];
extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);

void func_800FE520(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078C30;
    func_800ADE84(object + 1124, 2);
    *(void **)(object + 180) = D_80078CA0;
    func_800BA1B4(object, mode);
}
