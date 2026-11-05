typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct VObject {
    char pad[180];
    VEntry *vtbl;
    char rest[212 - 184];
} VObject;

extern VEntry D_80071400[];
extern VEntry D_80086598[];
extern VEntry D_8008A490[];

extern void func_800AF064(void *p, int flag);
extern void func_800CC4B4(void *p, int flag);
extern void func_800ADDA4(void *p, int flag);
extern void func_800CCE84(void *p, int flag);
extern void func_8007F1A4(void *p, int flag);
extern void func_800D3460(void *p, int flag);
extern void func_800D8170(void *p, int flag);
extern void func_800AC3A4(void *p, int flag);
extern void func_800A9C2C(void *p, int flag);
extern void func_800BF4D4(void *p, int flag);
extern void func_800AE4D8(void *p, int flag);

static inline void base_dtor(VObject *p, int flag)
{
    p->vtbl = D_80086598;
    func_800ADDA4(p, flag);
}

static inline void list_dtor(VObject *list, int flag)
{
    VObject *arr;
    VObject *it;

    list->vtbl = D_8008A490;
    arr = (VObject *)((char *)list + 240);
    if (arr != 0) {
        VObject *first;
        it = arr + 50;
        if (arr != it) {
            first = arr;
            do {
                it--;
                it->vtbl[1].fn((char *)it + it->vtbl[1].offset, 2);
            } while (first != it);
        }
    }
    base_dtor(list, flag);
}

void func_800E3050(unsigned char *state, int flag)
{
    double *slots;
    double *s;

    ((VObject *)state)->vtbl = D_80071400;
    func_800AF064(state + 25424, 2);
    func_800CC4B4(state + 23124, 2);
    base_dtor((VObject *)(state + 22904), 2);
    base_dtor((VObject *)(state + 22684), 2);
    base_dtor((VObject *)(state + 22464), 2);
    func_800ADDA4(state + 21972, 2);
    func_800ADDA4(state + 21760, 2);
    func_800ADDA4(state + 21548, 2);
    func_800ADDA4(state + 21336, 2);
    func_800ADDA4(state + 21124, 2);
    func_800ADDA4(state + 20912, 2);
    func_800ADDA4(state + 20700, 2);
    func_800CCE84(state + 19952, 2);
    func_8007F1A4(state + 14520, 2);
    base_dtor((VObject *)(state + 14284), 2);
    func_800D3460(state + 12884, 2);

    list_dtor((VObject *)(state + 2016), 2);

    func_800D8170(state + 1632, 2);
    slots = (double *)(state + 1564);
    if (slots != 0) {
        s = slots + 8;
        while (slots != s) {
            s--;
        }
    }
    func_800AC3A4(state + 1360, 2);
    func_800A9C2C(state + 1116, 2);
    func_800BF4D4(state + 600, 2);
    func_800AE4D8(state + 224, 2);
    func_800AC3A4(state, flag);
}
