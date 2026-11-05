extern void func_800B9E9C(void *object, int animation, int mode, float scale,
                          int extra);
extern void func_800B9A68(void *object, int animation);

void func_800EBE9C(unsigned char *object)
{
    unsigned int offset;
    unsigned char *entry;

    if (object[1040] < object[1041]) {
        offset = object[1040] * 12;
        entry = object + offset;
        func_800B9E9C(object, *(int *)(entry + 928), -1,
                      *(float *)(object + 632), 0);
        offset = object[1040] * 12;
        entry = object + offset;
        func_800B9A68(object, *(int *)(entry + 932));
        offset = object[1040] * 12;
        entry = object + offset;
        object[1089] = entry[939];
    }
}
