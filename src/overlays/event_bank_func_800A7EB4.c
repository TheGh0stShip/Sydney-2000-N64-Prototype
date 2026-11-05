typedef struct VTableEntry {
    char pad[8];
    short offset;
    void (*destroy)(void *object, int mode);
} VTableEntry;

extern unsigned char D_80071668[];
extern unsigned char D_8008A490[];
extern unsigned char D_80086598[];
extern void func_800AC3A4(void *object, int mode);
extern void func_800A9C2C(void *object, int mode);
extern void func_800CCE84(void *object, int mode);
extern void func_800CEF98(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_80077064(void *object, int mode);
extern void func_800A2C34(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800D8170(void *object, int mode);
extern void func_8007F1A4(void *object, int mode);
extern void func_800D3460(void *object, int mode);
extern void func_800BB5CC(void *object, int mode);

void func_800A7EB4(unsigned char *object, int mode)
{
    unsigned char *holder;
    unsigned char *entry;
    VTableEntry *vtable;

    *(void **)(object + 180) = D_80071668;
    func_800AC3A4(object + 31716, 2);
    func_800A9C2C(object + 31472, 2);
    func_800CCE84(object + 31248, 2);
    func_800CEF98(object + 29936, 2);

    holder = object + 19068;
    *(void **)(holder + 180) = D_8008A490;
    if (object + 19308 != 0) {
        entry = object + 29908;
        while (object + 19308 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    *(void **)(holder + 180) = D_80086598;
    func_800ADDA4(holder, 2);

    func_80077064(object + 13804, 2);
    func_800A2C34(object + 13304, 2);
    func_800ADE84(object + 13092, 2);
    func_800ADE84(object + 12880, 2);
    func_800ADE84(object + 12668, 2);
    func_800ADE84(object + 12456, 2);
    func_800ADE84(object + 12244, 2);
    func_800D8170(object + 11784, 2);

    entry = object + 6352;
    func_8007F1A4(entry, 2);
    if (object + 2152 != 0) {
        while (object + 2152 != entry) {
            entry -= 1400;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    func_800D3460(object + 752, 2);
    func_800BB5CC(object + 216, 2);
    func_800AC3A4(object, mode);
}
