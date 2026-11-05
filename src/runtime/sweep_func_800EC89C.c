extern unsigned char *func_800EA114(void *pool, int index);

void func_800EC89C(unsigned char *object, float *pos, float *vel, short kind)
{
    unsigned char *item = func_800EA114(object + 244, -1);
    float x, y, z;

    x = pos[0];
    y = pos[1];
    z = pos[2];
    *(float *)(item + 12) = x;
    *(float *)(item + 16) = y;
    *(float *)(item + 20) = z;
    x = vel[0];
    y = vel[1];
    z = vel[2];
    *(int *)(item + 4) = 2100;
    *(short *)(item + 2) = kind;
    *(int *)(item + 8) = 0;
    item[0] = 1;
    item[1] = 0;
    *(float *)(item + 24) = x;
    *(float *)(item + 28) = y;
    *(float *)(item + 32) = z;
}
