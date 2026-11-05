/* Object destructor: install base vtable, drop live count, destroy members. */
typedef struct Obj {
    char pad0[180];
    void *vtbl;
    char pad1[272 - 184];
    char member[1];
} Obj;

extern void func_800ADE84(void *obj, int flags);
extern unsigned char D_800F1A40;
extern char D_80084E78[];

void func_800A1664(Obj *obj, int flags)
{
    obj->vtbl = D_80084E78;
    D_800F1A40 = D_800F1A40 - 1;
    func_800ADE84(obj->member, 2);
    func_800ADE84(obj, flags);
}
