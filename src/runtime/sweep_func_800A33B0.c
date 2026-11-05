extern int func_800A3054(void *object, int a);
extern int func_800A3240(void *object);
extern int func_800A32CC(void *object);
extern int func_8001D824(void *object);

int func_800A33B0(void *object)
{
    int total;

    func_800A3054(object, 0);
    total = func_800A3240(object) + func_800A32CC(object);
    func_8001D824(object);
    return total;
}
