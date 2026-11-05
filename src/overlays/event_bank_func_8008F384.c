typedef struct VTableEntry {
    char pad[8];
    short offset;
    void (*destroy)(void *object, int mode);
} VTableEntry;

extern unsigned char D_80071430[];
extern unsigned char D_8008A490[];
extern unsigned char D_80086598[];
extern void func_800AC3A4(void *object, int mode);
extern void func_800A9C2C(void *object, int mode);
extern void func_800CCE84(void *object, int mode);
extern void func_800CEF98(void *object, int mode);
extern void func_800771F8(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_80081890(void *object, int mode);
extern void func_8009F8B4(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800D8170(void *object, int mode);
extern void func_8007F1A4(void *object, int mode);
extern void func_800D3460(void *object, int mode);
extern void func_800AE4D8(void *object, int mode);

void func_8008F384(unsigned char *object, int mode)
{
    unsigned char *entry;
    unsigned char *member;
    VTableEntry *vtable;

    *(void **)(object + 180) = D_80071430;
    if (object + 0x8464 != 0) {
        entry = object + 0x8888;
        while (object + 0x8464 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    func_800AC3A4(object + 0x8358, 2);
    func_800A9C2C(object + 0x8264, 2);
    func_800CCE84(object + 0x8184, 2);
    func_800CEF98(object + 31844, 2);
    func_800771F8(object + 26580, 2);
    func_800ADE84(object + 26356, 2);
    func_80081890(object + 25832, 2);
    func_8009F8B4(object + 23196, 2);
    func_800AC3A4(object + 23008, 2);
    member = object + 12136;
    *(void **)(member + 180) = D_8008A490;
    if (object + 12376 != 0) {
        entry = object + 22976;
        while (object + 12376 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    *(void **)(member + 180) = D_80086598;
    func_800ADDA4(member, 2);
    func_800D8170(object + 11728, 2);
    func_8007F1A4(object + 6296, 2);
    if (object + 2096 != 0) {
        entry = object + 6296;
        while (object + 2096 != entry) {
            entry -= 1400;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    func_800D3460(object + 696, 2);
    func_800AE4D8(object + 216, 2);
    func_800AC3A4(object, mode);
}
