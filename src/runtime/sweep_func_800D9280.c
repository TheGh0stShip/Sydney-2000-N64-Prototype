typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)(void *, int);
} VEntry;

typedef struct VTable {
    char pad[8];
    VEntry destroy;
    char pad2[8];
    short release_offset;
    short release_pad;
    void (*release)(void *);
} VTable;

typedef struct Child {
    char pad[180];
    VTable *vtbl;
} Child;

typedef struct Obj {
    char pad[180];
    VTable *vtbl;
    char pad2[316];
    Child *a;
    Child *b;
} Obj;

extern VTable D_8008A858;
extern char D_800F2758[];
extern void func_800AA658(void *, Child **);
extern void func_800BA1B4(Obj *, int);

void func_800D9280(Obj *obj, int flags)
{
    obj->vtbl = &D_8008A858;
    if (obj->a != 0) {
        obj->a->vtbl->release((char *)obj->a + obj->a->vtbl->release_offset);
        obj->a->vtbl->destroy.fn((char *)obj->a + obj->a->vtbl->destroy.offset, 2);
        func_800AA658(D_800F2758, &obj->a);
    }
    if (obj->b != 0) {
        obj->b->vtbl->release((char *)obj->b + obj->b->vtbl->release_offset);
        obj->b->vtbl->destroy.fn((char *)obj->b + obj->b->vtbl->destroy.offset, 2);
        func_800AA658(D_800F2758, &obj->b);
    }
    func_800BA1B4(obj, flags);
}
