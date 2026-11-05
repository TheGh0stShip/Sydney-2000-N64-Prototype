extern void func_800BA1B4(void *object);
extern unsigned char D_80071458[];

void func_80095BD0(unsigned char *object)
{
    *(void **)(object + 180) = D_80071458;
    func_800BA1B4(object);
}
