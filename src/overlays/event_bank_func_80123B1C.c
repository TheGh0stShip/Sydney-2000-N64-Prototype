extern void func_800D29E0(char *obj);
extern void func_800B2158(char *slot, int arg);

void func_80123B1C(char *obj)
{
    unsigned char i;

    func_800D29E0(obj + 216);
    for (i = 0; i < 10; i++) {
        func_800B2158(obj + 1616 + i * 220, 0);
    }
    *(unsigned char *)(obj + 3846) = 0;
}
