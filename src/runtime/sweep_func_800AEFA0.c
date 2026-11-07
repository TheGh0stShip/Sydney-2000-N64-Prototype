typedef unsigned char u8;
typedef struct { int a, b, c; void *d; int e; int f, g; } Ent;
typedef struct { int count; Ent *ents; void *p8; } S;
extern char D_800F2758[];
extern void func_800AA658(void *, void *);
static inline void clr(Ent *e)
{
    func_800AA658(D_800F2758, &e->d);
    e->a = 0;
    e->b = 0;
    e->c = 0;
    e->d = 0;
    e->e = 0;
}
void func_800AEFA0(S *s)
{
    char *h = D_800F2758;
    if (s->ents) {
        u8 i = 0;
        while (1) {
            if (!(i < s->count)) break;
            clr(&s->ents[i]);
            i++;
        }
        func_800AA658(h, &s->ents);
    }
    if (s->p8) {
        func_800AA658(h, &s->p8);
    }
}
