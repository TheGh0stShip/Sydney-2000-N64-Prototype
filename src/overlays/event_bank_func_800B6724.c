extern unsigned char D_80086598[];
extern void func_800ADDA4(void *object, int mode);
extern void func_800CE380(void *object, int mode);

void func_800B6724(unsigned char *object, int mode)
{
    unsigned char *vtable = D_80086598;
    unsigned char *part;

    part = object + 1772;
    *(void **)(part + 180) = vtable;
    func_800ADDA4(part, 2);
    part = object + 1552;
    *(void **)(part + 180) = vtable;
    func_800ADDA4(part, 2);
    part = object + 1332;
    *(void **)(part + 180) = vtable;
    func_800ADDA4(part, 2);
    part = object + 1112;
    *(void **)(part + 180) = vtable;
    func_800ADDA4(part, 2);
    func_800CE380(object + 900, 2);
    func_800ADDA4(object + 688, 2);
    func_800ADDA4(object + 476, 2);
    func_800ADDA4(object + 264, 2);
    func_800ADDA4(object, mode);
}
