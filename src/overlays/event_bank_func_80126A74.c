extern void func_8009D8F8(void *object, int flag, int condition);

void func_80126A74(unsigned char *object)
{
    unsigned char *nested = *(unsigned char **)(object + 4);
    int flag = *(int *)(object + 740) == 0;
    int condition = nested[1556] != 5;
    func_8009D8F8(object + 2076, flag, condition);
}
