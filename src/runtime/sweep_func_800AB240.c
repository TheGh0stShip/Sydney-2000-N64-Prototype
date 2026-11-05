extern void func_800B3AFC(void *dst, int value, int size);
extern void func_800AB534(void *object);

void func_800AB240(unsigned char *object)
{
    *(short *)(object + 12) = 0;
    *(short *)(object + 16) = 0;
    func_800B3AFC(*(void **)(object + 0), 0, *(unsigned short *)(object + 14) * 24);
    func_800B3AFC(*(void **)(object + 4), 0, (*(unsigned short *)(object + 14) + 1) * 4);
    func_800AB534(object);
}
