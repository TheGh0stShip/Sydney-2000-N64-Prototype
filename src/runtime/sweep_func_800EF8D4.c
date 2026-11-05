extern void func_800AD434(void *object, float angle, int mode);
extern void func_800EF894(void *object);

void func_800EF8D4(unsigned char *object)
{
    unsigned char *mat = object + 96;

    *(int *)(object + 480) = 0;
    *(int *)(object + 216) = 0;
    *(int *)(object + 196) = 0;
    *(int *)(object + 0) = 66;
    *(int *)(mat + 36) = 0;
    *(int *)(mat + 32) = 0;
    *(int *)(mat + 24) = 0;
    *(int *)(mat + 16) = 0;
    *(int *)(mat + 8) = 0;
    *(int *)(mat + 4) = 0;
    *(int *)(mat + 72) = 0;
    *(int *)(mat + 68) = 0;
    *(int *)(mat + 64) = 0;
    *(float *)(mat + 40) = 1.0f;
    *(float *)(mat + 20) = 1.0f;
    *(float *)(object + 96) = 1.0f;
    func_800AD434(mat, 0.19634952f, 3);
    func_800EF894(object);
}
