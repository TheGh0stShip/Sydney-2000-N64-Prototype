extern void func_800ADE84(void *p, int v);
extern void func_800D3460(void *p, int v);
extern void func_800AE4D8(void *p, int v);
extern void func_800AC3A4(void *p, int v);
extern unsigned char D_8008A038[];
extern unsigned char D_8008A168[];

void func_800D5318(unsigned char *object, int arg)
{
    *(void **)(object + 180) = D_8008A038;
    func_800ADE84(object + 2536, 2);
    func_800ADE84(object + 2324, 2);
    func_800D3460(object + 660, 2);
    *(void **)(object + 180) = D_8008A168;
    func_800AE4D8(object + 220, 2);
    func_800AC3A4(object, arg);
}
