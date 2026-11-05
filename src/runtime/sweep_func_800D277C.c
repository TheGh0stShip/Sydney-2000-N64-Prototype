extern char D_80089E48[];
extern char D_80086598[];
extern char D_800865F0[];
extern void func_800CC4B4(void *, int);
extern void func_800ADDA4(void *, int);
extern void func_800CE380(void *, int);

#define VTBL(p) (*(void **)((char *)(p) + 180))

void func_800D277C(char *obj, int flags)
{
    char *sub;

    VTBL(obj) = D_80089E48;
    func_800CC4B4(obj + 3456, 2);
    sub = obj + 3236;
    VTBL(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = obj + 3016;
    VTBL(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = obj + 2796;
    VTBL(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800ADDA4(obj + 2552, 2);
    func_800ADDA4(obj + 2340, 2);
    func_800ADDA4(obj + 2128, 2);
    func_800ADDA4(obj + 1916, 2);
    func_800ADDA4(obj + 1704, 2);
    func_800ADDA4(obj + 1492, 2);
    func_800ADDA4(obj + 1280, 2);
    func_800ADDA4(obj + 1068, 2);
    func_800ADDA4(obj + 856, 2);
    sub = obj + 644;
    VTBL(sub) = D_800865F0;
    func_800ADDA4(sub, 2);
    sub = obj + 424;
    VTBL(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800CE380(obj + 212, 2);
    func_800ADDA4(obj, flags);
}
