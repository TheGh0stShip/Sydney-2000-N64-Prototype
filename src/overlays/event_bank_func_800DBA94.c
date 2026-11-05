extern int D_800F2728;
extern void func_8009BD50(int id);
extern void func_800AC334(void *object);
extern void func_800766DC(void *object);
extern void func_800D771C(void *object);

void func_800DBA94(unsigned char *object)
{
    unsigned char *sub;

    func_8009BD50(object[1557]);
    sub = object + 1360;
    if (*(int *)(sub + 4) != 0) {
        func_800AC334(sub);
    }
    func_800766DC(object);
    func_800AC334(object + 19952);
    func_800D771C(object + 2016);
    D_800F2728 = 0;
    *(int *)(object + 172) = 0;
    *(int *)(object + 184) = 0;
    object[1557] = object[1558];
}
