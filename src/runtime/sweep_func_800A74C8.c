typedef struct VEnt { short delta; short index; void (*fn)(void *, int); } VEnt;
typedef struct Elem { char pad[180]; VEnt *vptr; char pad2[212 - 184]; } Elem;
typedef struct Obj { char pad[180]; void *vptr; char pad2[204 - 184]; Elem arr[10]; } Obj;
extern char D_800858D0[];
extern void func_800AC3A4(Obj *, int);
void func_800A74C8(Obj *a, int flag)
{
    Elem *base;
    Elem *q;
    a->vptr = D_800858D0;
    base = a->arr;
    if (base != 0) {
        Elem *p;
        q = base + 10;
        if (base != q) { p = base;
            do {
                q--;
                q->vptr[1].fn((char *)q + q->vptr[1].delta, 2);
            } while (p != q);
        }
    }
    func_800AC3A4(a, flag);
}
