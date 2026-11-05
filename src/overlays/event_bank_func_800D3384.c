typedef struct {
    short pad0[4];
    short thisOffset;
    short pad1;
    void (*destroy)(void *self, int flags);
} EventVTableEntry;

extern void func_800BA1B4(void *object, int flags);
extern void func_800ADE84(void *object, int flags);
extern void func_80081DC8(unsigned char *object, int flags);
extern unsigned char D_80070918[];

void func_800D3384(unsigned char *object, int flags)
{
    unsigned char *entry;
    EventVTableEntry *vt;

    *(void **)(object + 180) = D_80070918;
    func_800BA1B4(object + 17792, 2);
    if (object + 17352 != 0) {
        entry = object + 17776;
        while (object + 17352 != entry) {
            entry -= 212;
            vt = *(EventVTableEntry **)(entry + 180);
            vt->destroy(entry + vt->thisOffset, 2);
        }
    }
    func_800ADE84(object + 17140, 2);
    func_80081DC8(object, flags);
}
