extern unsigned char D_800857E0[];
extern void func_800AC3D4(void *object);

void *func_800A6C64(unsigned char *object)
{
    func_800AC3D4(object);
    *(void **)(object + 180) = D_800857E0;
    return object;
}
