typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self, int flags);
} VtblEntry;

typedef struct VObject {
    char pad[180];
    VtblEntry *vtbl;
} VObject;

extern char D_80086598[];
extern void func_800ADDA4(void *obj, int flags);
extern void func_800CE380(void *obj, int flags);
extern void func_800CD8A0(void *obj, int flags);
extern void func_80004380(void *ptr);

void func_8009C10C(char *obj, int flags)
{
    {
        char *p = obj + 5048;
        char *base;
        func_800ADDA4(p, 2);
        base = obj + 4412;
        if (base != 0) {
            if (base != p) {
                char *b = base;
                do {
                    p -= 212;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }
    {
        char *p = obj + 4200;
        char *base;
        func_800ADDA4(p, 2);
        base = obj + 3564;
        if (base != 0) {
            if (base != p) {
                char *b = base;
                do {
                    p -= 212;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }
    {
        char *base = obj + 2928;
        if (base != 0) {
            char *p = obj + 3564;
            if (base != p) {
                char *b = base;
                do {
                    p -= 212;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }
    {
        char *p = obj + 2704;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
    }
    func_800CE380(obj + 2492, 2);
    func_800CD8A0(obj + 1584, 2);
    {
        char *sub = obj + 1324;
        char *base;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(sub, 2);
        base = obj + 664;
        if (base != 0) {
            char *p = sub;
            if (base != p) {
                char *b = base;
                do {
                    p -= 220;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }
    {
        char *base = obj + 4;
        if (base != 0) {
            char *p = obj + 664;
            if (base != p) {
                char *b = base;
                do {
                    p -= 220;
                    ((VObject *)p)->vtbl[1].func(p + ((VObject *)p)->vtbl[1].delta, 2);
                } while (b != p);
            }
        }
    }

    if (flags & 1) {
        func_80004380(obj);
    }
}
