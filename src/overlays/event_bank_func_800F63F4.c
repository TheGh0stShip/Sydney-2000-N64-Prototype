extern void *func_800AEF6C(void *table, int index);
extern void func_800AE72C(void *object, void *owner, void *entry);

void func_800F63F4(unsigned char *object)
{
    float *source;
    float *dest;
    float *second;

    func_800AE72C(object + 652, object,
                  func_800AEF6C(*(unsigned char **)(object + 4) + 25424,
                                object[733]));
    *(float *)(object + 84) -= *(float *)(object + 1240);
    *(float *)(object + 92) -= *(float *)(object + 1244);
    source = (float *)(object + 20);
    dest = (float *)(object + 368);
    dest[0] = source[16];
    dest[1] = source[17];
    dest[2] = source[18];
    second = (float *)(object + 392);
    second[0] = source[16];
    second[1] = source[17];
    second[2] = source[18];
}
