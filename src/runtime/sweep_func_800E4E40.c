extern void func_800E9A2C(void *entry, int value, int enabled);
extern void func_800E8714(void *entry);
extern void func_800E90AC(void *entry, int value);

void func_800E4E40(unsigned char *object)
{
    void *entry = *(void **)(object + 184);
    func_800E9A2C(entry, 1024, 1);
    entry = *(void **)(object + 184);
    if (entry != 0) {
        func_800E8714(entry);
        func_800E90AC(*(void **)(object + 184), 0);
    }
}
