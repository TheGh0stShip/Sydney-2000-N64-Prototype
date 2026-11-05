extern void func_800CB514(void *object);
extern void func_800CB38C(void *object);
extern void func_800CB0D0(void *object);
extern void func_800CB034(void *object);

void func_800CB6BC(unsigned char *object)
{
    func_800CB514(object);
    func_800CB38C(object);
    func_800CB0D0(object);
    if ((*(unsigned short *)(object + 3164) & 2) != 0) {
        func_800CB034(object);
    }
}
