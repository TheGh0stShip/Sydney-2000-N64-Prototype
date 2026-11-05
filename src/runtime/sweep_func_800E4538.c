extern void func_800C8500(void *object);
extern void func_800C8120(void *object, int value, int mode);
extern void func_800E9A2C(void *object, int a, int b);
extern void func_800E8714(void *object);
extern void func_800E90AC(void *object, int value);

void func_800E4538(unsigned char *object)
{
    unsigned char *sub = *(unsigned char **)(object + 188) + 28540;

    if (sub[425] != 23) {
        int value = *(int *)(sub + 4);

        func_800C8500(sub);
        sub[425] = 23;
        func_800C8120(sub, value, 0);
    }
    func_800E9A2C(*(void **)(object + 188), 1024, 1);
    if (*(void **)(object + 188) != 0) {
        func_800E8714(*(void **)(object + 188));
        func_800E90AC(*(void **)(object + 188), 0);
    }
}
