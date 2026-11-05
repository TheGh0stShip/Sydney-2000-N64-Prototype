typedef struct Elem { char pad[16]; } Elem;
typedef struct Obj { char pad[180]; void *vtable; char pad2[516 - 184]; Elem elems[24]; } Obj;
extern char D_8008C140[];
extern void func_800AC3A4(Obj *o);

void func_800F0930(Obj *o)
{
    Elem *base = o->elems;
    if (base != 0) {
        Elem *p = base + 24;
        while (base != p) {
            p--;
        }
    }
    o->vtable = D_8008C140;
    func_800AC3A4(o);
}
