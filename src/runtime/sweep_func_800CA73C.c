/* Destructor: reinstall this class's vtable, destroy the embedded array of
 * twenty elements in reverse order (virtual slot 1, flag 2), then chain to
 * the base-class destructor. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Elem {
    char pad[180];
    VEntry *vtbl;
    char rest[212 - 184];
} Elem;

typedef struct Obj {
    char pad[180];
    void *vtbl;
    int pad2;
    Elem elems[20];
} Obj;

extern char D_800895D8[];
extern void func_800AC3A4(Obj *o, int flags);

void func_800CA73C(Obj *o, int flags)
{
    Elem *p;

    o->vtbl = D_800895D8;
    if (o->elems != 0) {
        p = o->elems + 20;
        while (o->elems != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    func_800AC3A4(o, flags);
}
