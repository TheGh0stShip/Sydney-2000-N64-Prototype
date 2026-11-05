/* Destructor: reinstall this class's vtables, destroy the trailing member,
 * destroy four embedded element arrays in reverse order (virtual slot 1,
 * flag 2), then chain to the base-class destructor. */
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
    Elem d[3];
    Elem c[3];
    Elem b[2];
    Elem a[5];
    Elem m;
} Obj;

extern char D_80089660[];
extern char D_80086598[];
extern void func_800ADDA4(Elem *e, int flags);
extern void func_800AC3A4(Obj *o, int flags);

void func_800CA968(Obj *o, int flags)
{
    Elem *p;
    Elem *m;

    o->vtbl = D_80089660;
    m = &o->m;
    m->vtbl = (VEntry *)D_80086598;
    func_800ADDA4(m, 2);
    if (o->a != 0) {
        p = o->a + 5;
        while (o->a != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    if (o->b != 0) {
        p = o->b + 2;
        while (o->b != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    if (o->c != 0) {
        p = o->c + 3;
        while (o->c != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    if (o->d != 0) {
        p = o->d + 3;
        while (o->d != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    func_800AC3A4(o, flags);
}
