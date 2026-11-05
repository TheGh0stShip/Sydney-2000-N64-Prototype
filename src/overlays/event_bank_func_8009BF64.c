typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self, int flags);
} VtblEntry;

extern char D_80071520[];
extern char D_8008A490[];
extern char D_80086598[];
extern void func_800AC3A4(void *obj, int flags);
extern void func_800A9C2C(void *obj, int flags);
extern void func_800CCE84(void *obj, int flags);
extern void func_800ADDA4(void *obj, int flags);
extern void func_80076B1C(void *obj, int flags);
extern void func_800CEF98(void *obj, int flags);
extern void func_800A21D0(void *obj, int flags);
extern void func_800D8170(void *obj, int flags);
extern void func_8007F1A4(void *obj, int flags);
extern void func_800D3460(void *obj, int flags);
extern void func_800AE4D8(void *obj, int flags);

typedef struct VObject {
    char pad[180];
    VtblEntry *vtbl;
} VObject;

void func_8009BF64(char *obj, int flags)
{
    char *sub;

    ((VObject *)obj)->vtbl = (VtblEntry *)D_80071520;

    {
        char *base = obj + 0x805C;
        if (base != 0) {
            char *p = obj + 0x806C;
            while (base != p) {
                p -= 8;
            }
        }
    }

    func_800AC3A4(obj + 32660, 2);
    func_800AC3A4(obj + 32472, 2);
    func_800A9C2C(obj + 32228, 2);
    func_800CCE84(obj + 31992, 2);

    sub = obj + 21124;
    ((VObject *)sub)->vtbl = (VtblEntry *)D_8008A490;
    {
        char *base = obj + 21364;
        if (base != 0) {
            char *p = obj + 31964;
            if (base != p) {
                char *b = base;
                do {
                    p -= 212;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }
    ((VObject *)sub)->vtbl = (VtblEntry *)D_80086598;
    func_800ADDA4(sub, 2);

    func_80076B1C(obj + 15860, 2);
    func_800CEF98(obj + 14548, 2);
    func_800A21D0(obj + 12140, 2);
    func_800D8170(obj + 11728, 2);

    {
        char *p = obj + 6296;
        char *base;
        func_8007F1A4(p, 2);
        base = obj + 2096;
        if (base != 0) {
            if (base != p) {
                char *b = base;
                do {
                    p -= 1400;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }

    func_800D3460(obj + 696, 2);
    func_800AE4D8(obj + 216, 2);
    func_800AC3A4(obj, flags);
}
