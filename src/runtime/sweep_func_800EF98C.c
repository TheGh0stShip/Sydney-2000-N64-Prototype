extern void func_800EF89C(void *object);

void func_800EF98C(unsigned char *object)
{
    *(void **)(object + 240) = 0;
    *(void **)(object + 216) = 0;
    *(void **)(object + 196) = 0;
    *(int *)object = 66;
    func_800EF89C(object);
}
