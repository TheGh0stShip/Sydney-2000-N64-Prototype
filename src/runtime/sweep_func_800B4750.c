extern void func_800ABA54(void *object, int flags);
extern void func_800AB48C(void *object, int flags);
extern unsigned char D_800F26F4[];
extern unsigned char D_800F26E0[];

void func_800B4750(void)
{
    func_800ABA54(D_800F26F4, 2);
    func_800AB48C(D_800F26E0, 2);
}
