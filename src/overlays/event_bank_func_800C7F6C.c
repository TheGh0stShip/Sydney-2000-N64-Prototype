extern char D_80070930[];
extern void func_800ADE84(void *p, int n);
extern void func_80081DC8(void *p, int b);

void func_800C7F6C(char *obj, int b)
{
    *(int *)(obj + 180) = (int)D_80070930;
    func_800ADE84(obj + 17380, 2);
    func_800ADE84(obj + 17164, 2);
    func_80081DC8(obj, b);
}
