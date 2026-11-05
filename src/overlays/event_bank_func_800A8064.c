typedef struct VTableEntry {
    char pad[8];
    short offset;
    void (*destroy)(void *object, int mode);
} VTableEntry;

extern unsigned char D_80086598[];
extern void func_800ADDA4(void *object, int mode);
extern void func_800CE380(void *object, int mode);
extern void func_800CD8A0(void *object, int mode);
extern void func_80004380(void *object);

void func_800A8064(unsigned char *object, int mode)
{
    unsigned char *entry;
    unsigned char *part;
    unsigned char *child;
    VTableEntry *vtable;

    func_800ADDA4(object + 5048, 2);
    if (object + 4412 != 0) {
        entry = object + 5048;
        while (object + 4412 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    func_800ADDA4(object + 4200, 2);
    if (object + 3564 != 0) {
        entry = object + 4200;
        while (object + 3564 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    if (object + 2928 != 0) {
        entry = object + 3564;
        while (object + 2928 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    child = object + 2704;
    *(void **)(child + 180) = D_80086598;
    func_800ADDA4(child, 2);
    func_800CE380(object + 2492, 2);
    func_800CD8A0(object + 1584, 2);
    part = object + 1324;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);
    if (object + 664 != 0) {
        entry = part;
        while (object + 664 != entry) {
            entry -= 220;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    if (object + 4 != 0) {
        entry = object + 664;
        while (object + 4 != entry) {
            entry -= 220;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    if (mode & 1) {
        func_80004380(object);
    }
}
