extern void func_800AD58C(void *object, int x, int y, int flags);
extern void func_800AD2A8(void *object, void *in, float *out, int flags);
extern void func_800AD9E8(void *object);

static inline void vec_sub(float *dst, float *a, float *b)
{
    dst[0] = a[0] - b[0];
    dst[1] = a[1] - b[1];
    dst[2] = a[2] - b[2];
}

void func_8011DEFC(unsigned char *object)
{
    float out[3];

    func_800AD58C(object + 20, *(int *)(object + 236), *(int *)(object + 240), 0);
    func_800AD2A8(object + 20, object + 212, out, 0);
    vec_sub((float *)(object + 84), (float *)(object + 224), out);
    func_800AD9E8(object);
}
