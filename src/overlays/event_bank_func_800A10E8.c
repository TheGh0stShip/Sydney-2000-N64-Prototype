typedef struct VtblEntry {
    short delta;
    short index;
    void (*func)(void *self, int flags);
} VtblEntry;

typedef struct VObject {
    char pad[180];
    VtblEntry *vtbl;
} VObject;

extern char D_80071280[];
extern char D_8008C680[];
extern char D_80071338[];
extern char D_8008C140[];
extern char D_80089E48[];
extern char D_80086598[];
extern char D_800865F0[];
extern char D_8007E368[];
extern char D_8008BE48[];
extern char D_8008A490[];
extern char D_8008BF48[];
extern void func_800AC3A4(void *obj, int flags);
extern void func_800AF064(void *obj, int flags);
extern void func_800A9C2C(void *obj, int flags);
extern void func_800CCE84(void *obj, int flags);
extern void func_800CC4B4(void *obj, int flags);
extern void func_800ADDA4(void *obj, int flags);
extern void func_800CE380(void *obj, int flags);
extern void func_800ADE84(void *obj, int flags);
extern void func_800E57A4(void *obj, int flags);
extern void func_800A63CC(void *obj, int flags);
extern void func_800D3460(void *obj, int flags);
extern void func_800D8170(void *obj, int flags);
extern void func_800AE4D8(void *obj, int flags);

void func_800A10E8(char *obj, int flags)
{
    ((VObject *)obj)->vtbl = (VtblEntry *)D_80071280;

    {
        char *sub = obj + 24180;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_8008C680;
        ((VObject *)(obj + 24272))->vtbl = (VtblEntry *)D_80071338;
        ((VObject *)(obj + 24244))->vtbl = (VtblEntry *)D_80071338;
        ((VObject *)(obj + 24216))->vtbl = (VtblEntry *)D_80071338;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_8008C140;
        func_800AC3A4(sub, 2);
    }
    func_800AF064(obj + 24152, 2);

    {
        char *base = obj + 24048;
        if (base != 0) {
            char *p = obj + 24064;
            while (base != p) {
                p -= 8;
            }
        }
    }

    func_800A9C2C(obj + 23728, 2);
    func_800CCE84(obj + 23456, 2);

    {
        char *sub = obj + 18068;
        char *p;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_80089E48;
        func_800CC4B4(obj + 21524, 2);
        p = obj + 21304;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
        p = obj + 21084;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
        p = obj + 20864;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
        func_800ADDA4(obj + 20620, 2);
        func_800ADDA4(obj + 20408, 2);
        func_800ADDA4(obj + 20196, 2);
        func_800ADDA4(obj + 19984, 2);
        func_800ADDA4(obj + 19772, 2);
        func_800ADDA4(obj + 19560, 2);
        func_800ADDA4(obj + 19348, 2);
        func_800ADDA4(obj + 19136, 2);
        func_800ADDA4(obj + 18924, 2);
        p = obj + 18712;
        ((VObject *)p)->vtbl = (VtblEntry *)D_800865F0;
        func_800ADDA4(p, 2);
        p = obj + 18492;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
        func_800CE380(obj + 18280, 2);
        func_800ADDA4(sub, 2);
    }

    {
        char *sub = obj + 14656;
        char *p;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_8007E368;
        p = obj + 15392;
        ((VObject *)p)->vtbl = (VtblEntry *)D_8008BE48;
        func_800ADE84(p, 2);
        func_800E57A4(obj + 14852, 2);
        func_800A63CC(sub, 2);
        p = obj + 14420;
        ((VObject *)p)->vtbl = (VtblEntry *)D_80086598;
        func_800ADDA4(p, 2);
    }

    func_800D3460(obj + 13020, 2);

    {
        char *sub = obj + 2152;
        ((VObject *)sub)->vtbl = (VtblEntry *)D_8008A490;
        {
            char *base = obj + 2392;
            if (base != 0) {
                char *p = obj + 12992;
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
    }

    func_800D8170(obj + 1768, 2);
    {
        char *p = obj + 780;
        ((VObject *)p)->vtbl = (VtblEntry *)D_8008BF48;
        func_800AE4D8(p, 2);
    }
    func_800AE4D8(obj + 256, 2);
    func_800AC3A4(obj, flags);
}
