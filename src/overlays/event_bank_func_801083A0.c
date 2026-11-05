extern void func_800B3870(void *dst, void *src, int size);
extern void func_800B9FA4(void *obj, int slot, int index, int value, int a, int b);
extern void func_800B9BD4(void *obj, int mode, float *a, float *b, float *c, int d);
extern void func_800B9964(void *obj, float *a, float *b, float *c);

void func_801083A0(char *obj)
{
    float c[4];
    float a[4];
    float b[2];
    char *src;
    float *dst;

    src = obj + 20;
    func_800B3870(src, obj + 848, 76);
    *(float *)(obj + 368) = *(float *)(src + 64);
    dst = (float *)(obj + 368);
    dst[1] = *(float *)(src + 68);
    dst[2] = *(float *)(src + 72);
    func_800B9FA4(obj, 11, -1, *(int *)(obj + 632), 0, 0);
    func_800B9BD4(obj, 1, a, b, c, 0);
    func_800B9964(obj, a, b, c);
}
