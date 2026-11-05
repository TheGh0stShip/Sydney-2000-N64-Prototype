extern unsigned char *func_800EA114(void *object, int mode);

void func_800ED788(unsigned char *object, unsigned char *source)
{
    unsigned char *part;
    float *pos;

    if (source != 0) {
        part = func_800EA114(object + 192, 0);
        pos = (float *)(source + 84);
        *(float *)(part + 12) = pos[0];
        *(float *)(part + 16) = pos[1];
        *(float *)(part + 20) = pos[2];
        *(float *)(part + 36) = 49.150497f;
    }
}
