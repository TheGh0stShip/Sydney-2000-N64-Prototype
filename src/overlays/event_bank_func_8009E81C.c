typedef struct VTableEntry {
    char pad[24];
    short offset;
    void (*reset)(void *object);
} VTableEntry;

typedef struct HandleSet {
    void *owner;
    int first;
    int second;
    int count;
    short x;
    short y;
} HandleSet;

extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern unsigned char D_800759E0[];
extern unsigned char D_800F4D00[];
extern HandleSet D_800F26B0;
extern void func_80075194(void);
extern void func_8009BDC4(void);
extern int func_80017D54(void);
extern void func_800ED930(void *object);
extern void func_800BC274(void *object);
extern void func_800BC0B4(void);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_800AC25C(void *object, int a, int b, int c);
extern void func_800D1E80(void *object);
extern void func_800ADC1C(void *object);
extern void func_800CCE4C(void *object);
extern void func_800AA658(void *owner, void *handle);
extern void func_800A8850(void *object);
extern void func_800AEFA0(void *object);
extern void func_800D6EA0(void *object);
extern void func_800AC334(void *object);
extern void func_800D29E0(void *object);
extern void func_80017B24(int value);
extern void func_800D52A8(void *object);
extern void func_800BAC24(void);
extern void func_8007E3B0(void *object);
extern void func_8009C100(void);

void func_8009E81C(unsigned char *object)
{
    unsigned char *part;
    VTableEntry *vtable;
    void *owner;

    func_80075194();
    func_8009BDC4();
    if (func_80017D54() != 0) {
        func_800ED930(object + 24180);
    }
    func_800BC274(D_800F2AD8);
    func_800BC0B4();
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800AC25C(object, 107, 7, 0);
    func_800D1E80(object + 18068);

    part = object + 23456;
    func_800ADC1C(part);
    vtable = *(VTableEntry **)(part + 180);
    vtable->reset(part + vtable->offset);
    part[176] = 0;
    func_800CCE4C(part);

    if (*(int *)(object + 24044) != 0) {
        func_800AA658(D_800F2758, object + 24044);
    }
    func_800A8850(object + 23728);
    func_800AEFA0(D_800759E0);

    part = object + 14420;
    func_800D6EA0(part);
    func_800AC334(part);
    part = object + 13020;
    func_800D29E0(part);
    func_800AC334(part);
    func_800AC334(object + 2152);
    func_80017B24(*(int *)(object + 192));
    func_800D52A8(D_800F4D00);

    owner = D_800F26B0.owner;
    if (owner != 0) {
        D_800F26B0.owner = 0;
        if (D_800F26B0.first != 0) {
            func_800AA658(owner, &D_800F26B0.first);
        }
        if (D_800F26B0.second != 0) {
            func_800AA658(owner, &D_800F26B0.second);
        }
        D_800F26B0.x = 0;
        D_800F26B0.y = 0;
        D_800F26B0.count = 0;
        D_800F26B0.owner = 0;
    }

    func_800BAC24();
    part = object + 14656;
    func_800AC334(part);
    func_8007E3B0(part);
    func_800AC334(object + 23728);
    func_8009C100();
    func_800AACB0(D_800F26E0, object, 0);
    object[24039] = 23;
    *(int *)(object + 172) = 2;
}
