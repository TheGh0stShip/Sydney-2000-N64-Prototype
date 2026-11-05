typedef struct {
    unsigned char data[76];
} Record;

extern void func_800B3870(void *dst, void *src, int size);

int func_800B97D4(unsigned char *object, unsigned short index, void *dst)
{
    short *count = *(short **)(*(unsigned char **)(object + 196) + 28);

    if (index > *count) {
        return 1;
    }
    func_800B3870(dst, &(*(Record **)(object + 352))[index], 76);
    return 1;
}
