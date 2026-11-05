extern char D_80070960[];
extern void func_800AE4D8(void *p, int n);
extern void func_800ADE84(void *p, int n);
extern void func_80081DC8(void *p, int b);

void func_800CAC44(char *obj, int b)
{
    *(int *)(obj + 180) = (int)D_80070960;
    func_800AE4D8(obj + 17784, 2);
    func_800ADE84(obj + 17568, 2);
    func_800ADE84(obj + 17352, 2);
    func_800ADE84(obj + 17136, 2);
    func_80081DC8(obj, b);
}
