extern unsigned char D_800F26E0[];
extern int D_800F2744;
extern void func_800AB2A4(void *table, int value, int size, void *object, int a, int b);

void func_800B63F4(unsigned char *object)
{
    object[23419] = 0;
    object[23417] = 0;
    object[23416]++;
    func_800AB2A4(D_800F26E0, D_800F2744, 24, object, 0, 0);
}
