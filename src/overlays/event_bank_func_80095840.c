typedef struct VTableEntry {
    char pad[8];
    short offset;
    void (*destroy)(void *object, int mode);
} VTableEntry;

extern unsigned char D_80071418[];
extern unsigned char D_80084CF0[];
extern unsigned char D_80080A78[];
extern unsigned char D_8008A490[];
extern unsigned char D_80086598[];
extern void func_800AC3A4(void *object, int mode);
extern void func_800A9C2C(void *object, int mode);
extern void func_800CCE84(void *object, int mode);
extern void func_80076744(void *object, int mode);
extern void func_800A0FAC(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800D8170(void *object, int mode);
extern void func_8007F1A4(void *object, int mode);
extern void func_800D3460(void *object, int mode);
extern void func_800AE4D8(void *object, int mode);

void func_80095840(unsigned char *object, int mode)
{
    unsigned char *entry;
    unsigned char *member;
    VTableEntry *vtable;

    *(void **)(object + 180) = D_80071418;
    if (object + 30132 != 0) {
        unsigned char *slot = object + 30148;

        while (object + 30132 != slot) {
            slot -= 8;
        }
    }
    func_800AC3A4(object + 29932, 2);
    func_800A9C2C(object + 29688, 2);
    func_800CCE84(object + 29452, 2);
    func_80076744(object + 24188, 2);
    func_800A0FAC(object + 23684, 2);
    {
        unsigned char *child = object + 23448;

        *(void **)(child + 180) = D_80084CF0;
        func_800ADE84(child, 2);
    }
    {
        unsigned char *child = object + 22996;

        *(void **)(child + 180) = D_80080A78;
        func_800BA1B4(child, 2);
    }
    func_800D8170(object + 22596, 2);
    func_8007F1A4(object + 17164, 2);
    if (object + 12964 != 0) {
        entry = object + 17164;
        while (object + 12964 != entry) {
            entry -= 1400;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    func_800D3460(object + 11564, 2);
    member = object + 696;
    *(void **)(member + 180) = D_8008A490;
    if (object + 936 != 0) {
        entry = object + 11536;
        while (object + 936 != entry) {
            entry -= 212;
            vtable = *(VTableEntry **)(entry + 180);
            vtable->destroy(entry + vtable->offset, 2);
        }
    }
    *(void **)(member + 180) = D_80086598;
    func_800ADDA4(member, 2);
    func_800AE4D8(object + 216, 2);
    func_800AC3A4(object, mode);
}
