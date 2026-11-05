typedef struct {
    char pad[180];
    void *vtable;
    char pad2[36];
} Part;

typedef struct {
    char pad[312];
    char anim[656];
    Part parts[4];
} Obj;

extern char D_80086598[];
extern void func_800ADDA4(void *, int);
extern void func_800BB1F4(void *, int);
extern void func_800AC3A4(void *, int);

static __inline__ void part_init(Part *p)
{
    p->vtable = D_80086598;
    func_800ADDA4(p, 2);
}

void func_80071E00(Obj *self, int arg)
{
    part_init(&self->parts[3]);
    part_init(&self->parts[2]);
    part_init(&self->parts[1]);
    part_init(&self->parts[0]);
    func_800BB1F4(self->anim, 2);
    func_800AC3A4(self, arg);
}
