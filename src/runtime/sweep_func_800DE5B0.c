extern void func_800DE424(void *object);
extern void func_800E8714(void *entry);
extern void func_800E90AC(void *entry, int value);

void func_800DE5B0(unsigned char *object)
{
    void *entry;
    func_800DE424(object);
    entry = *(void **)(object + 188);
    if (entry != 0) {
        func_800E8714(entry);
        func_800E90AC(*(void **)(object + 188), 0);
    }
}
