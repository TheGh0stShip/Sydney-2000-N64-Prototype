#define D_80080AC8 (*(float *)0x80080AC8)
#define D_80080ACC (*(float *)0x80080ACC)
#define D_80080AD0 (*(float *)0x80080AD0)
#define D_80080AD4 (*(float *)0x80080AD4)

void func_8011D638(unsigned char *object)
{
    float c0 = D_80080AC8;
    float c1 = D_80080ACC;
    float c2 = D_80080AD0;
    unsigned char *state = object + 0x14;
    float value;
    float c3;

    *(int *)(state + 0x24) = 0;
    *(int *)(state + 0x20) = 0;
    *(int *)(state + 0x18) = 0;
    *(int *)(state + 0x10) = 0;
    *(int *)(state + 0x08) = 0;
    *(int *)(state + 0x04) = 0;
    *(int *)(state + 0x48) = 0;
    *(int *)(state + 0x44) = 0;
    *(int *)(state + 0x40) = 0;
    *(float *)(state + 0x28) = c0;
    *(float *)(state + 0x14) = c0;
    value = *(float *)(object + 0x1AC);
    *(float *)(object + 0x14) = c0;
    c3 = D_80080AD4;
    *(float *)(object + 0x54) = c1;
    *(float *)(object + 0x5C) = c2;
    *(float *)(object + 0x170) = c1;
    *(float *)(object + 0x58) = value - c3;
    *(float *)(object + 0x178) = c2;
    *(int *)(object + 0x1B8) = 0;
    *(int *)(object + 0x1B0) = 0;
    *(float *)(object + 0x174) = value - c3;
}
