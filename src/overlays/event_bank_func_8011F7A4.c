extern void func_800815C0(void *object, int mode, int enabled);
extern void func_800B3870(void *destination, void *source, int size);

void func_8011F7A4(unsigned char *object, int mode)
{
    float zero;
    float low;
    float high;

    low = *(float *)0x80080C6C;
    high = *(float *)0x80080C70;
    zero = 0.0f;
    *(float *)(object + 4312) = zero;
    *(float *)(object + 4324) = zero;
    *(float *)(object + 4308) = low;
    *(float *)(object + 4316) = high;
    *(float *)(object + 4320) = low;
    *(float *)(object + 4328) = high;
    *(float *)(object + 4288) = zero;
    *(float *)(object + 4280) = zero;
    *(float *)(object + 4276) = zero;
    *(float *)(object + 4272) = zero;
    *(float *)(object + 4268) = zero;
    *(float *)(object + 4264) = zero;
    func_800815C0(object, mode, 1);
    *(int *)(object + 4296) = 0;
    *(float *)(object + 4376) = zero;
    *(float *)(object + 4372) = zero;
    *(float *)(object + 4368) = zero;
    *(float *)(object + 4364) = zero;
    *(float *)(object + 4360) = zero;
    *(float *)(object + 4356) = zero;
    func_800B3870(object + 4380, object + 20, 76);
}
