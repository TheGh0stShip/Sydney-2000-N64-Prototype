extern void func_800AED04(void *object);

void func_800AE3B4(unsigned char *object)
{
    *(int *)(object + 188) = 1;
    *(int *)(object + 268) = 0;
    *(int *)(object + 184) = 0;
    *(int *)(object + 0) = 2;
    *(float *)(object + 244) = 1.5707964f;
    func_800AED04(object + 292);
    *(short *)(object + 196) = 0;
    *(int *)(object + 200) = 0;
    *(float *)(object + 248) = 0.033333335f;
    *(float *)(object + 252) = 1.0f;
}
