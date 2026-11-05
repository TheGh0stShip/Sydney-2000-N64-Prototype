extern char D_800708C8[];
extern void func_800ADE84(void *p, int n);
extern void func_80081DC8(void *p, int b);

void func_800C4DE4(char *obj, int b)
{
    *(int *)(obj + 180) = (int)D_800708C8;
    func_800ADE84(obj + 17152, 2);
    func_80081DC8(obj, b);
}
