typedef struct { char pad[0xD68]; int flags; } RuntimeDesc;
typedef struct { char pad[0x10]; unsigned short id; } Target;
typedef struct { int unk0; void *obj; } Args;
extern RuntimeDesc *runtimeDescriptorBase;
extern char D_800F26E0[];
extern int D_800F2744;
extern Target *func_800DCCF4(void *obj);
extern void func_800AB2A4(void *a, int b, int c, void *d, int e, int f);

int func_800D69EC(Args *args) {
    void *obj;
    Target *t;

    if (runtimeDescriptorBase->flags & 0xFFF) {
        obj = args->obj;
        t = func_800DCCF4(obj);
        func_800AB2A4(D_800F26E0, D_800F2744, 10, obj, 0, t->id);
    }
    return -1;
}
