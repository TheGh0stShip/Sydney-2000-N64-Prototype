extern unsigned char D_80078B18[];
extern unsigned char D_80078B98[];
extern unsigned char D_80086598[];
extern void func_800ADE84(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800D3460(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);

void func_800F2CA0(unsigned char *object, int mode)
{
    unsigned char *part;

    *(void **)(object + 180) = D_80078B18;
    func_800ADE84(object + 4052, 2);

    part = object + 3832;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);
    part = object + 3612;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);

    func_800D3460(object + 2212, 2);
    func_800D3460(object + 812, 2);
    *(void **)(object + 180) = D_80078B98;
    func_800BA1B4(object, mode);
}
