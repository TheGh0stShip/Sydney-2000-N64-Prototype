extern unsigned char *func_800EA308(void *pool, int kind, int data);

void func_800EC92C(unsigned char *object, float *pos)
{
    unsigned char *p = func_800EA308(object + 216, 897, *(int *)(object + 200));
    float x, y, z;

    *(short *)(p + 2) = 15;
    *(short *)(p + 46) = 6;
    *(short *)(p + 48) = 682;
    *(short *)(p + 44) = 0;
    x = pos[0];
    y = pos[1];
    z = pos[2];
    *(unsigned int *)(p + 52) = 0xB2FFFFFF;
    *(unsigned int *)(p + 56) = 0x00FFFFFF;
    *(float *)(p + 4) = x;
    *(float *)(p + 8) = y;
    *(float *)(p + 12) = z;
    *(float *)(p + 40) = 0.010922333f;
    *(float *)(p + 36) = 1.0f;
}
