typedef struct { char pad[16]; short offset; short pad2; void (*fn)(char *, void *); } VEntry;
extern char D_800F4D00[];
extern void func_800ADC54(char *, int);
extern void func_800ADC38(char *);
void func_8009D878(char *base)
{
    char *g = D_800F4D00;
    char *obj = base + 24688;
    VEntry *v = *(VEntry **)(obj + 180);
    v->fn(obj + v->offset, g);
    func_800ADC54(obj, 1 << *(int *)(g + 216));
    *(char *)(obj + 176) = 1;
    *(int *)(obj + 192) &= ~4;
    func_800ADC38(obj);
}
