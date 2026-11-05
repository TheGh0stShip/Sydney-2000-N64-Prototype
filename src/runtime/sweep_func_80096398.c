struct VEntry {
    short pad0;
    short pad2;
    short pad4;
    short pad6;
    short offset;
    short pad10;
    void (*func)(void *object, int mode);
};
extern unsigned char D_800F2758[];
extern void func_800AA648(void *list);
extern void func_80011054(int mode);
extern void func_8001AE8C(void);

void func_80096398(int unused, unsigned char *object)
{
    if (object != 0) {
        struct VEntry *entry = *(struct VEntry **)(object + 180);
        entry->func(object + entry->offset, 3);
    }
    func_800AA648(D_800F2758);
    func_80011054(2);
    func_8001AE8C();
}
