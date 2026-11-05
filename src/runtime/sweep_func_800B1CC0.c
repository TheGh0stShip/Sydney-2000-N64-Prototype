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
    char pad2[76];
    Elem elems[2];
} Obj;

extern char D_80086510[];
extern char D_80086598[];
extern void func_800ADDA4(Obj *obj, int flags);

void func_800B1CC0(Obj *obj, int flags) {
    Elem *begin;
    Elem *e;

    obj->vtbl = D_80086510;
    begin = obj->elems;
    if (begin != 0) {
        e = obj->elems + 2;
        if (begin != e) {
            Elem *p = begin;
            do {
                e--;
                e->vtbl->entries[1].func((char *)e + e->vtbl->entries[1].delta, 2);
            } while (p != e);
        }
    }
    obj->vtbl = D_80086598;
    func_800ADDA4(obj, flags);
}
