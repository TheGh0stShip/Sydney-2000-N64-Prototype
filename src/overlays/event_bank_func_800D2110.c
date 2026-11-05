typedef struct {
    short pad0[4];
    short thisOffset;
    short pad1;
    void (*destroy)(void *self, int flags);
} EventVTableEntry;

extern void func_800ADE84(void *object, int flags);
extern void func_80081DC8(unsigned char *object, int flags);
extern unsigned char D_80070B00[];

void func_800D2110(unsigned char *object, int flags)
{
    unsigned char *entry;
    EventVTableEntry *vt;

    *(void **)(object + 180) = D_80070B00;
    if (object + 17568 != 0) {
        entry = object + 18204;
        while (object + 17568 != entry) {
            entry -= 212;
            vt = *(EventVTableEntry **)(entry + 180);
            vt->destroy(entry + vt->thisOffset, 2);
        }
    }
    func_800ADE84(object + 17356, 2);
    func_800ADE84(object + 17140, 2);
    func_80081DC8(object, flags);
}
