extern unsigned char D_80078B90[];
extern unsigned char D_80078C40[];
extern unsigned char D_80089750[];
extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);

void func_800F6694(unsigned char *object, int mode)
{
    unsigned char *part = object + 1004;

    *(void **)(object + 180) = D_80078B90;
    *(void **)(part + 180) = D_80089750;
    func_800ADE84(part, 2);
    func_800ADE84(object + 792, 2);
    *(void **)(object + 180) = D_80078C40;
    func_800BA1B4(object, mode);
}
