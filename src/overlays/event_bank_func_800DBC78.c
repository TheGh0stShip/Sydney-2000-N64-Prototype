typedef struct {
    short pad0[4];
    short thisOffset;
    short pad1;
    void (*destroy)(void *self, int flags);
} EventVTableEntry;

extern unsigned char D_80071368[];
extern unsigned char D_80086598[];
extern unsigned char D_8008A490[];
extern void func_800AF064(void *object, int flags);
extern void func_800CC4B4(void *object, int flags);
extern void func_800ADDA4(void *object, int flags);
extern void func_800CCE84(void *object, int flags);
extern void func_8007F1A4(void *object, int flags);
extern void func_800D3460(void *object, int flags);
extern void func_800D8170(void *object, int flags);
extern void func_800AC3A4(void *object, int flags);
extern void func_800A9C2C(void *object, int flags);
extern void func_800BF4D4(void *object, int flags);
extern void func_800AE4D8(void *object, int flags);

void func_800DBC78(unsigned char *object, int flags)
{
    unsigned char *entry;
    unsigned char *list;
    unsigned char *slot;
    unsigned char *sub;
    EventVTableEntry *vt;

    *(void **)(object + 180) = D_80071368;
    func_800AF064(object + 25052, 2);
    func_800CC4B4(object + 22784, 2);
    sub = object + 22564;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = object + 22344;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    sub = object + 22124;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800ADDA4(object + 21632, 2);
    func_800ADDA4(object + 21420, 2);
    func_800ADDA4(object + 21208, 2);
    func_800ADDA4(object + 20996, 2);
    func_800ADDA4(object + 20784, 2);
    func_800ADDA4(object + 20572, 2);
    func_800ADDA4(object + 20360, 2);
    func_800CCE84(object + 19952, 2);
    func_8007F1A4(object + 14520, 2);
    sub = object + 14284;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    func_800D3460(object + 12884, 2);

    list = object + 2016;
    *(void **)(list + 180) = D_8008A490;
    if (object + 2256 != 0) {
        entry = object + 12856;
        while (object + 2256 != entry) {
            entry -= 212;
            vt = *(EventVTableEntry **)(entry + 180);
            vt->destroy(entry + vt->thisOffset, 2);
        }
    }
    *(void **)(list + 180) = D_80086598;
    func_800ADDA4(list, 2);
    func_800D8170(object + 1632, 2);
    if (object + 1564 != 0) {
        slot = object + 1628;
        while (object + 1564 != slot) {
            slot -= 8;
        }
    }
    func_800AC3A4(object + 1360, 2);
    func_800A9C2C(object + 1116, 2);
    func_800BF4D4(object + 600, 2);
    func_800AE4D8(object + 224, 2);
    func_800AC3A4(object, flags);
}
