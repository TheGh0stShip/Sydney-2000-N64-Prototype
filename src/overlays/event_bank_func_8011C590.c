extern void func_80080E20(void *object, int value);

void func_8011C590(unsigned char *object)
{
    *(int *)(object + 260) = 0;
    *(int *)(object + 172) = 0;
    *(int *)(object + 264) = 0;
    *(int *)(object + 268) = 0;
    func_80080E20(object, *(int *)(object + 260));
}
