#define D_80071700 (*(float *)0x80071700)

extern void func_800B3870(void *dest, void *src, int size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *source);
extern void func_800A9B78(void *object, void *part, int mode, int value,
                          int kind);

void func_800A7D6C(unsigned char *object, unsigned char *source, int value)
{
    unsigned char *part;

    func_800B3870(object + 31736, source + 20, 76);
    if (*(float *)(object + 31804) < D_80071700) {
        *(float *)(object + 31804) = D_80071700;
    }
    part = object + 31716;
    if (*(int *)(part + 4) != 0) {
        func_800AC334(part);
    }
    func_800AC37C(part, source);
    func_800A9B78(object + 31472, part, 1, value, 2);
}
