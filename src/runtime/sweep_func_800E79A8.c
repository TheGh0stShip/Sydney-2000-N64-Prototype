extern char D_800F2758;
extern void func_800AA658(void *, void **);
extern void func_800E792C(void *);

void func_800E79A8(char *object)
{
    func_800E792C(object + 220);
    func_800AA658(&D_800F2758, (void **)(object + 212));
}
