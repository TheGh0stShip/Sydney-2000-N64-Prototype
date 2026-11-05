typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct VObject {
    char pad[180];
    VEntry *vtbl;
} VObject;

typedef struct Element {
    char pad[180];
    VEntry *vtbl;
    char rest[404 - 184];
} Element;

extern unsigned char D_800F26F4[];
extern unsigned char D_800F3BC0[];
extern unsigned char D_800F1AE0[];
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];

extern void func_800AB934(void *list, void *object);
extern void func_800C013C(void *object);
extern void func_800A32CC(void *object);
extern void func_800AC334(void *object);
extern void func_800C0168(void *object);
extern void func_800BC274(void *object);
extern void func_800AB240(void *object);
extern void func_800ADC1C(void *object);
extern void func_800AEFA0(void *object);
extern void func_800A8850(void *object);
extern void func_80017B24(int value);
extern void func_800BAC24(void);
extern void func_8007E7A0(VObject *object);
extern void func_8007E230(VObject *object);
extern void func_8007E080(VObject *object);
extern void func_8007E394(VObject *object);
extern void func_8007E098(VObject *object);
extern void func_800AA658(void *list, void *slot);
extern void func_800A7910(void *object);
extern void func_800AC308(void *object);
extern void func_80017A90(int value);
extern void func_80014384(void);
extern void func_800137FC(void);

#define VCALL(obj, idx) (obj)->vtbl[idx].fn((char *)(obj) + (obj)->vtbl[idx].offset)
#define VCALL1(obj, idx, a) (obj)->vtbl[idx].fn((char *)(obj) + (obj)->vtbl[idx].offset, a)

void func_80072060(unsigned char *state)
{
    unsigned char i;

    if (state[4456] != 0) {
        func_800AB934(D_800F26F4, state);
    }
    func_800C013C(D_800F3BC0);
    func_800A32CC(D_800F1AE0);
    func_800AC334(D_800F3BC0);
    func_800C0168(D_800F3BC0);
    func_800BC274(D_800F2AD8);
    func_800AB240(D_800F26E0);
    func_800ADC1C(state + 240);

    for (i = 0; i < 3; i++) {
        VCALL(&((Element *)(state + 1724))[i], 9);
        VCALL(&((Element *)(state + 1724))[i], 3);
    }

    func_800AEFA0(state + 4248);
    func_800A8850(state + 4004);
    func_800AC334(state + 2968);
    func_80017B24(*(int *)(state + 2936));
    func_800BAC24();

    if (*(VObject **)(state + 184) != 0) {
        func_8007E7A0(*(VObject **)(state + 184));
        VCALL(*(VObject **)(state + 184), 3);
        VCALL1(*(VObject **)(state + 184), 1, 2);
        func_800AA658(D_800F2758, state + 184);
    }
    if (*(VObject **)(state + 188) != 0) {
        func_8007E230(*(VObject **)(state + 188));
        VCALL(*(VObject **)(state + 188), 3);
        VCALL1(*(VObject **)(state + 188), 1, 2);
        func_800AA658(D_800F2758, state + 188);
    }
    if (*(VObject **)(state + 192) != 0) {
        func_8007E080(*(VObject **)(state + 192));
        VCALL(*(VObject **)(state + 192), 3);
        VCALL1(*(VObject **)(state + 192), 1, 2);
        func_800AA658(D_800F2758, state + 192);
    }
    if (*(VObject **)(state + 196) != 0) {
        func_8007E394(*(VObject **)(state + 196));
        VCALL(*(VObject **)(state + 196), 3);
        VCALL1(*(VObject **)(state + 196), 1, 2);
        func_800AA658(D_800F2758, state + 196);
    }
    if (*(VObject **)(state + 200) != 0) {
        func_8007E098(*(VObject **)(state + 200));
        VCALL(*(VObject **)(state + 200), 3);
        VCALL1(*(VObject **)(state + 200), 1, 2);
        func_800AA658(D_800F2758, state + 200);
    }

    func_800AC334(state + 4464);
    func_800A7910(state + 4464);
    func_800AC308(state);
    func_80017A90(0x80000000);
    func_80014384();
    func_800137FC();
}
