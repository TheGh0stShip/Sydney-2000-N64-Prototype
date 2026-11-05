extern unsigned char D_80071440[];
extern void func_800BA1B4(void *object, int mode);

void func_800E3248(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80071440;
    func_800BA1B4(object, mode);
}
