extern int func_800AE5C0(void *self, void *pos);
extern void func_800AE8C0(void *self, void *src);

int func_800AEAE8(unsigned char *self, unsigned char *src)
{
    float *pos = (float *)(src + 84);
    float *dst;
    int result = func_800AE5C0(self, pos);
    if (*(int *)(self + 12) != 0) {
        func_800AE8C0(self, src);
    }
    dst = (float *)(self + 16);
    dst[0] = pos[0];
    dst[1] = pos[1];
    dst[2] = pos[2];
    return result;
}
