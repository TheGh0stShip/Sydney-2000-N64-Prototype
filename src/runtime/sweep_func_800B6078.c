extern void func_800AE4D8(void *object);
extern unsigned char D_800868E0[];

void func_800B6078(unsigned char *object)
{
    *(void **)(object + 180) = D_800868E0;
    func_800AE4D8(object);
}
