typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short d; short pad; void (*f)(); } VEnt;
typedef struct { char pad[24]; VEnt e; } VTab;
typedef struct { char pad[180]; VTab *vt; } Node;
typedef struct { char b[8]; } Slot;
typedef struct {
    char pad0[184]; void *p184;
    char pad1[192 - 188]; Node *child; int pad196; Slot *slots; void **ptrs;
    char pad2[216 - 208]; void *p216;
    char pad3[226 - 220]; u16 nslots; u16 nptrs;
} Obj;
extern char D_800F2758[];
extern char D_800F26E0[];
extern void func_800AA658(void *, void *);
extern void func_800AA068(Slot *);
extern void func_800AACB0(void *, Obj *, int);
void func_800A8850(Obj *o)
{
    u8 i;
    char *heap = D_800F2758;
    Node *c = o->child;
    if (c) c->vt->e.f((char *)c + c->vt->e.d);
    func_800AA658(heap, &o->p216);
    for (i = 0; i < o->nslots; i++) func_800AA068(&o->slots[i]);
    func_800AA658(heap, &o->slots);
    for (i = 0; i < o->nptrs; i++) func_800AA658(heap, &o->ptrs[i]);
    func_800AA658(heap, &o->ptrs);
    func_800AA658(heap, &o->p184);
    func_800AACB0(D_800F26E0, o, 0);
}
