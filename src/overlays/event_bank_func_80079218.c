int func_80079218(unsigned char *object, int index, float *result)
{
    unsigned char *entry;

    if ((int)(object[0x10000 + 2841] - 1) < (index & 0xFF)) {
        return 0;
    }
    entry = *(unsigned char **)(object + (index & 0xFF) * 27024 + 28568);
    *result = *(float *)(entry + 2752);
    return 1;
}
