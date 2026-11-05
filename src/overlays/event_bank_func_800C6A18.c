extern char D_80070980[];
extern void func_800ADE84(void *p, int n);
extern void func_80081DC8(void *p, int b);

void func_800C6A18(char *obj, int b)
{
    *(int *)(obj + 180) = (int)D_80070980;
    func_800ADE84(obj + 17784, 2);
    func_800ADE84(obj + 17364, 2);
    func_800ADE84(obj + 17152, 2);
    func_80081DC8(obj, b);
}
