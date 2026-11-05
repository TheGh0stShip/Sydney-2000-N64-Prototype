extern int D_800F2728;
extern void func_8009BD50(int mode);
extern void func_800739B0(void *object);
extern void func_800AC334(void *object);
extern void func_800D771C(void *object);

void func_800A0F54(unsigned char *object)
{
    func_8009BD50(5);
    *(int *)(object + 24112) = -1;
    func_800739B0(object);
    func_800AC334(object + 23456);
    func_800D771C(object + 2152);
    D_800F2728 = 0;
    *(int *)(object + 172) = 0;
    *(int *)(object + 24092) = 0;
    object[24041] = object[24042];
}
