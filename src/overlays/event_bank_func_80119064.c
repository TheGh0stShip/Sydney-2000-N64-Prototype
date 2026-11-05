extern unsigned char D_8007E040[];
extern void func_800A63F0(void *object);

void *func_80119064(unsigned char *object)
{
    func_800A63F0(object);
    *(void **)(object + 180) = D_8007E040;
    return object;
}
