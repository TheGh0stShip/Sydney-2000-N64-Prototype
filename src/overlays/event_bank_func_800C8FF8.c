extern char D_80070908[];
extern void func_800ADE84(void *p, int n);
extern void func_80081DC8(void *p, int b);

void func_800C8FF8(char *obj, int b)
{
    *(int *)(obj + 180) = (int)D_80070908;
    func_800ADE84(obj + 17372, 2);
    func_800ADE84(obj + 17156, 2);
    func_80081DC8(obj, b);
}
