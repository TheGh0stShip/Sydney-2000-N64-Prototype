extern void func_8009BD50(int state);
extern void func_800AC334(void *object);
extern void func_800768F4(void *object);
extern void func_800D771C(void *object);
extern void func_800B4794(int enable);
extern void func_80073D18(void *object);
extern int D_800F2728;

void func_80088370(unsigned char *object)
{
    unsigned char *sub;

    func_8009BD50(object[1557]);
    sub = object + 1360;
    if (*(int *)(sub + 4) != 0) {
        func_800AC334(sub);
    }
    func_800768F4(object);
    func_800AC334(object + 16436);
    func_800D771C(object + 2016);
    D_800F2728 = 0;
    *(int *)(object + 172) = 0;
    *(int *)(object + 184) = 0;
    object[1557] = object[1558];
    func_800B4794(1);
    func_80073D18(object);
    func_800B4794(0);
}
