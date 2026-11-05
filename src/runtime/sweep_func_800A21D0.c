extern unsigned char D_80084FF0[];
extern unsigned char D_80085068[];
extern void func_800A2198(void *object);
extern void func_800D3460(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);

void func_800A21D0(unsigned char *object, int mode)
{
    unsigned char *part;

    *(void **)(object + 180) = D_80084FF0;
    func_800A2198(object);
    func_800D3460(object + 964, 2);
    func_800ADE84(object + 680, 2);
    part = object + 404;
    *(void **)(part + 180) = D_80085068;
    func_800ADE84(part, 2);
    func_800BA1B4(object, mode);
}
