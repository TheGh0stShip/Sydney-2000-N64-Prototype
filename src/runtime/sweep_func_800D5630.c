extern void func_800ADE84(void *p, int v);
extern void func_800D3460(void *p, int v);
extern void func_800AE4D8(void *p, int v);
extern void func_800AC3A4(void *p, int v);
extern unsigned char D_800F5900[];
extern unsigned char D_8008A038[];
extern unsigned char D_8008A168[];

void func_800D5630(void)
{
    unsigned char *base = D_800F5900;

    *(void **)(base + 180) = D_8008A038;
    func_800ADE84(base + 2536, 2);
    func_800ADE84(base + 2324, 2);
    func_800D3460(base + 660, 2);
    *(void **)(base + 180) = D_8008A168;
    func_800AE4D8(base + 220, 2);
    func_800AC3A4(base, 2);
}
