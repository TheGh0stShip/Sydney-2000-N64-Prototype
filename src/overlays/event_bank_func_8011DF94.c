extern void func_8008115C(void *object);

void func_8011DF94(unsigned char *object)
{
    *(int *)(object + 236) = 0;
    *(int *)(object + 240) = 0;
    *(int *)(object + 244) = 0;
    *(int *)(object + 248) = 0;
    *(int *)(object + 252) = 0;
    *(unsigned short *)(object + 256) = 0;
    *(int *)(object + 172) = 0;
    func_8008115C(object);
}
