extern void func_800AC3A4(void *obj, int flags);
extern void func_800CC4B4(void *obj, int flags);
extern void func_800ADDA4(void *obj, int flags);
extern void func_800CCE84(void *obj, int flags);
extern void func_8007EEE4(void *obj, int flags);
extern void func_800D3460(void *obj, int flags);
extern void func_800D8170(void *obj, int flags);
extern void func_800A9C2C(void *obj, int flags);
extern void func_800BF4D4(void *obj, int flags);
extern void func_800AE4D8(void *obj, int flags);
extern unsigned char D_80071390[];
extern unsigned char D_8008C2C0[];
extern unsigned char D_80071480[];
extern unsigned char D_8008C140[];
extern unsigned char D_80086598[];
extern unsigned char D_8008A490[];

typedef struct {
    short offset;
    short pad;
    void (*func)();
} VEntry;

#define VTABLE(p) (*(unsigned char **)((unsigned char *)(p) + 180))

void func_800885A4(unsigned char *object, int flags)
{
    unsigned char *sub;
    unsigned char *list;
    unsigned char *base;
    unsigned char *p;
    unsigned char *pairs;
    unsigned char *q;
    VEntry *entry;

    VTABLE(object) = D_80071390;
    sub = object + 21668;
    VTABLE(sub) = D_8008C2C0;
    *(unsigned char **)(object + 22024) = D_80071480;
    *(unsigned char **)(object + 21996) = D_80071480;
    *(unsigned char **)(object + 21968) = D_80071480;
    *(unsigned char **)(object + 21940) = D_80071480;
    *(unsigned char **)(object + 21912) = D_80071480;
    VTABLE(sub) = D_8008C140;
    func_800AC3A4(sub, 2);
    func_800CC4B4(object + 19268, 2);
    sub = object + 19048;
    VTABLE(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = object + 18828;
    VTABLE(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = object + 18608;
    VTABLE(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800ADDA4(object + 18116, 2);
    func_800ADDA4(object + 17904, 2);
    func_800ADDA4(object + 17692, 2);
    func_800ADDA4(object + 17480, 2);
    func_800ADDA4(object + 17268, 2);
    func_800ADDA4(object + 17056, 2);
    func_800ADDA4(object + 16844, 2);
    func_800CCE84(object + 16436, 2);
    func_8007EEE4(object + 14520, 2);
    sub = object + 14284;
    VTABLE(sub) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800D3460(object + 12884, 2);
    list = object + 2016;
    VTABLE(list) = D_8008A490;
    if (object + 2256 != 0) {
        p = object + 12856;
        if (object + 2256 != p) {
            base = object + 2256;
            do {
                p -= 212;
                entry = (VEntry *)(VTABLE(p) + 8);
                entry->func(p + entry->offset, 2);
            } while (base != p);
        }
    }
    VTABLE(list) = D_80086598;
    func_800ADDA4(list, 2);
    func_800D8170(object + 1632, 2);
    pairs = object + 1564;
    q = object + 1628;
    if (pairs != 0 && pairs != q) {
        do {
            q -= 8;
        } while (pairs != q);
    }
    func_800AC3A4(object + 1360, 2);
    func_800A9C2C(object + 1116, 2);
    func_800BF4D4(object + 600, 2);
    func_800AE4D8(object + 224, 2);
    func_800AC3A4(object, flags);
}
