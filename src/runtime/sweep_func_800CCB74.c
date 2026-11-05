extern void func_8001A248(void *p);
extern void func_800ADDA4(void *p, int arg);
extern unsigned char D_80089888[];

void func_800CCB74(unsigned char *object, int arg)
{
    *(void **)(object + 180) = D_80089888;
    if (*(int *)(object + 212) != 0) {
        func_8001A248(object + 212);
    }
    if (*(int *)(object + 216) != 0) {
        func_8001A248(object + 216);
    }
    if (*(int *)(object + 220) != 0) {
        func_8001A248(object + 220);
    }
    *(int *)(object + 216) = 0;
    *(int *)(object + 212) = 0;
    func_800ADDA4(object + 240, 2);
    func_800ADDA4(object, arg);
}
