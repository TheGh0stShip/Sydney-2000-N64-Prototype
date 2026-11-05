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
extern unsigned char D_800774C0[];
extern unsigned char D_800F7270[];
extern unsigned char D_80077280[];
extern unsigned char D_800F4D00[];
extern HandleSet D_800F26B0;
extern void func_8009BDC4(void);
extern void func_800BC274(void *object);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_80074E9C(void *object, int mode);
extern void func_800ADC1C(void *object);
extern void func_800AC334(void *object);
extern void func_800CEF1C(void *object);
extern void func_800AC25C(void *object, int a, int b, int c);
extern void func_800AA658(void *owner, void *handle);
extern void func_800A8850(void *object);
extern void func_800AEFA0(void *object);
extern void func_800D29E0(void *object);
extern void func_80097A30(void *object);
extern void func_8001A248(void *object);
extern void func_800CCE4C(void *object);
extern void func_800D771C(void *object);
extern void func_80017B24(int value);
extern void func_800D7F5C(void *object);
extern void func_800BAC24(void);
extern void func_8007E7A0(void *object);
extern void func_800D52A8(void *object);
extern void func_8009C100(void);

void func_800A5588(unsigned char *object)
{
    unsigned char *part;
    unsigned char *first;
    unsigned char *second;
    unsigned char *third;
    unsigned char *fourth;
    VTableEntry *vtable;
    void *owner;
    unsigned int i;

    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_80074E9C(object, 0);
    part = object + 13304;
    func_800ADC1C(part);
    func_800AC334(part);
    func_800ADC1C(object + 12880);
    func_800ADC1C(object + 12668);
    func_800ADC1C(object + 13092);

    part = object + 29936;
    vtable = *(VTableEntry **)(part + 180);
    vtable->reset(part + vtable->offset);
    part[176] = 0;
    func_800CEF1C(part);
    func_800AC25C(object, 107, 7, 0);
    if (*(int *)(object + 31924) != 0) {
        func_800AA658(D_800F2758, object + 31924);
    }
    if (*(int *)(object + 31972) != 0) {
        func_800AA658(D_800F2758, object + 31972);
    }
    part = object + 31472;
    func_800AC334(part);
    func_800A8850(part);
    func_800AEFA0(D_800774C0);

    first = object + 752;
    vtable = *(VTableEntry **)(first + 180);
    vtable->reset(first + vtable->offset);
    second = object + 2152;
    first[176] = 0;
    vtable = *(VTableEntry **)(second + 180);
    vtable->reset(second + vtable->offset);
    third = object + 3552;
    second[176] = 0;
    vtable = *(VTableEntry **)(third + 180);
    vtable->reset(third + vtable->offset);
    fourth = object + 4952;
    third[176] = 0;
    vtable = *(VTableEntry **)(fourth + 180);
    vtable->reset(fourth + vtable->offset);
    fourth[176] = 0;
    func_800D29E0(first);
    func_800D29E0(second);
    func_800D29E0(third);
    func_800D29E0(fourth);

    func_80097A30(object + 13804);
    func_8001A248(object + 12216);
    func_8001A248(object + 12220);
    func_800CCE4C(object + 31248);
    part = object + 19068;
    func_800D771C(part);
    vtable = *(VTableEntry **)(part + 180);
    vtable->reset(part + vtable->offset);
    part[176] = 0;
    func_800ADC1C(object + 12244);
    func_800AC334(object + 216);
    func_80017B24(*(int *)(object + 184));
    part = object + 11784;
    func_800AEFA0(D_800F7270);
    func_800D7F5C(part);
    for (i = 0; i < 8; i++) {
        *(int *)(part + 184) = 0;
        part += 4;
    }
    func_800AC334(object + 11784);
    func_800BAC24();
    part = object + 6352;
    func_800AEFA0(D_80077280);
    func_8007E7A0(part);
    func_800AC334(part);
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
    func_8009C100();
    *(int *)(object + 172) = 1;
}
