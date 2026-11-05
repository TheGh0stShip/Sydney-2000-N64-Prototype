extern void func_800B31EC(int value);

void *func_800B1B4C(unsigned char *object)
{
    unsigned char *nested = *(unsigned char **)(object + 220);
    void *result = *(void **)(nested + 28);
    func_800B31EC(0);
    return result;
}
