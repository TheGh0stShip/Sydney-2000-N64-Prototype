typedef struct {
    short delta;
    short index;
    void (*fn)();
} VEntry;

typedef struct {
    char pad[180];
    VEntry *vtbl;
    char pad2[212 - 184];
} Obj;

typedef struct {
    char pad[180];
    VEntry *vtbl;
    char pad2[236 - 184];
} Part;

typedef struct {
    Obj base;
    Part parts[4];
    Obj last;

    Obj items[4];
} Owner;

extern VEntry D_80086598[];
extern void func_800ADDA4(void *, int);

void func_800D3EFC(Owner *self, int flags)
{
    Obj *p;
    Part *q;

    if (self->items != 0) {
        p = &self->items[4];
        while (self->items != p) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
    func_800ADDA4(&self->last, 2);
    q = &self->parts[3];
    q->vtbl = D_80086598;
    func_800ADDA4(q, 2);
    q = &self->parts[2];
    q->vtbl = D_80086598;
    func_800ADDA4(q, 2);
    q = &self->parts[1];
    q->vtbl = D_80086598;
    func_800ADDA4(q, 2);
    q = &self->parts[0];
    q->vtbl = D_80086598;
    func_800ADDA4(q, 2);
    func_800ADDA4(self, flags);
}
