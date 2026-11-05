extern void func_8001D964(void);
extern void func_8001CA40(int value);

void func_800A31BC(unsigned char *object)
{
    if (*(int *)(object + 84) != 10 && *(int *)(object + 40) == 0) {
        func_8001D964();
        *(int *)(object + 40) = 0;
        func_8001D964();
        *(int *)(object + 40) = 1;
        func_8001CA40(*(int *)(object + 84));
    }
}
