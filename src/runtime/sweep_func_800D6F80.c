extern void func_800B360C(void *object, void *source);
extern void func_800B2158(void *object, int enabled);

void func_800D6F80(unsigned char *object, unsigned char *source)
{
    func_800B360C(object, source);
    *(int *)(object + 224) = *(int *)(source + 28);
    *(int *)(object + 220) = *(int *)(source + 24);
    *(int *)(object + 232) = *(int *)(source + 32);
    *(int *)(object + 228) = *(int *)(source + 32);
    if (*(int *)(object + 220) > 0) {
        func_800B2158(object, 0);
    }
}
