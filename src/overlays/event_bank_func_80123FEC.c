extern void func_8000673C(void *object);

void func_80123FEC(unsigned char *object, unsigned char a, unsigned char b, unsigned char c)
{
    object[10969] = a;
    object[10970] = b;
    object[10971] = c;
    *(int *)(object + 11008) = 1;
    func_8000673C(object + 10968);
}
