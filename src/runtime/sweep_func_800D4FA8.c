typedef struct {
    short delta;
    short index;
    void (*fn)();
} VEntry;

typedef struct {
    char pad[180];
    VEntry *vtbl;
    char pad2[220 - 184];
} Obj;

extern Obj D_801028B0[10];
extern char D_800F4D00[];
extern VEntry D_8008A038[];
extern VEntry D_8008A168[];
extern void func_800ADE84(void *, int);
extern void func_800D3460(void *, int);
extern void func_800AE4D8(void *, int);
extern void func_800AC3A4(void *, int);

void func_800D4FA8(void)
{
    Obj *p;

    if (D_801028B0 != 0) {
        p = &D_801028B0[10];
        while (p != D_801028B0) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    ((Obj *)D_800F4D00)->vtbl = D_8008A038;
    func_800ADE84(D_800F4D00 + 2536, 2);
    func_800ADE84(D_800F4D00 + 2324, 2);
    func_800D3460(D_800F4D00 + 660, 2);
    ((Obj *)D_800F4D00)->vtbl = D_8008A168;
    func_800AE4D8(D_800F4D00 + 220, 2);
    func_800AC3A4(D_800F4D00, 2);
}
