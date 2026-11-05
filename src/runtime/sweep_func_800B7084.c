extern void func_800B7034(void *object);
extern void func_800E9A2C(void *entry, int value, int enabled);
extern void func_800E8714(void *entry);
extern void func_800E90AC(void *entry, int value);

void func_800B7084(unsigned char *object)
{
    void *entry;
    func_800B7034(object);
    entry = *(void **)(object + 640);
    func_800E9A2C(entry, 1024, 1);
    entry = *(void **)(object + 640);
    if (entry != 0) {
        func_800E8714(entry);
        func_800E90AC(*(void **)(object + 640), 0);
    }
}
