extern void func_800CB5D8(void *object);
extern void func_800CB428(void *object);
extern void func_800CAAC8(void *object);

void func_800CB724(unsigned char *object)
{
    *(short *)(object + 3164) = 1;
    func_800CB5D8(object);
    func_800CB428(object);
    func_800CAAC8(object);
}
