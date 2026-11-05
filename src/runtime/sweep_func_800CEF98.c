extern void func_800ADDA4(void *p, int v);
extern unsigned char D_80089B88[];
extern unsigned char D_80086598[];

void func_800CEF98(unsigned char *object, int arg)
{
    unsigned char *sub;

    *(void **)(object + 180) = D_80089B88;
    sub = object + 1084;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800ADDA4(object + 872, 2);
    func_800ADDA4(object + 660, 2);
    func_800ADDA4(object + 448, 2);
    func_800ADDA4(object + 236, 2);
    func_800ADDA4(object, arg);
}
