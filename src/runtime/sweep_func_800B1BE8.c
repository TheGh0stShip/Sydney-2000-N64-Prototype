typedef struct { char pad[16]; short off1; short p1; void (*fn1)(char *, char *); char pad2[40]; short off2; short p2; void (*fn2)(char *); } VTbl;
extern char D_800F2758[];
extern char D_80086394[];
extern void func_800AA804(void *, char **, int, void *);
extern char *func_800AAA58(int, char *);
extern void func_800CE3A8(char *);
extern void func_800CE468(char *, int, int, int, int, int);
void func_800B1BE8(char *obj)
{
    char *child;
    VTbl *v;
    if (*(char **)(obj + 792) != 0) {
        return;
    }
    func_800AA804(D_800F2758, (char **)(obj + 792), 212, D_80086394);
    func_800CE3A8(func_800AAA58(212, *(char **)(obj + 792)));
    func_800CE468(*(char **)(obj + 792), 0, 0, 56, -4, 2);
    {
        char *c = *(char **)(obj + 792);
        *(char *)(c + 201) = 3;
        *(int *)(c + 192) |= 0x20000;
    }
    *(char *)(*(char **)(obj + 792) + 176) = 1;
    child = *(char **)(obj + 792);
    v = *(VTbl **)(child + 180);
    v->fn1(child + v->off1, obj);
    child = *(char **)(obj + 792);
    v = *(VTbl **)(child + 180);
    v->fn2(child + v->off2);
}
