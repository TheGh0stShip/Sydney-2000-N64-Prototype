typedef struct {
    short delta;
    short index;
    void (*func)(void *self, int flags);
} VtblEntry;

typedef struct {
    VtblEntry entries[2];
} Vtbl;

typedef struct {
    char pad[180];
    Vtbl *vtbl;
    char pad2[28];
} Elem;

typedef struct {
    char pad[180];
    void *vtbl;
    char pad2[336];
    Elem small[100];
    Elem large[50];
} Obj;

extern char D_80085A30[];
extern void func_800AC3A4(Obj *obj, int flags);

void func_800A8784(Obj *obj, int flags) {
    Elem *begin;
    Elem *e;

    obj->vtbl = D_80085A30;
    begin = obj->large;
    if (begin != 0) {
        e = obj->large + 50;
        if (begin != e) {
            Elem *p = begin;
            do {
                e--;
                e->vtbl->entries[1].func((char *)e + e->vtbl->entries[1].delta, 2);
            } while (p != e);
        }
    }
    begin = obj->small;
    if (begin != 0) {
        e = obj->small + 100;
        if (begin != e) {
            Elem *p = begin;
            do {
                e--;
                e->vtbl->entries[1].func((char *)e + e->vtbl->entries[1].delta, 2);
            } while (p != e);
        }
    }
    func_800AC3A4(obj, flags);
}
