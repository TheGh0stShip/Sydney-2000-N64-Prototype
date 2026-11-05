typedef struct VEntry {
    short offset;
    short pad;
    void (*fn)();
} VEntry;

typedef struct Actor {
    char pad0[180];
    VEntry *vtbl;
    char pad1[424 - 184];
    unsigned char slot;
    char pad2[2];
    signed char team;
} Actor;

typedef struct SlotEntry {
    char data[60];
} SlotEntry;

extern SlotEntry *D_800FC270;
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];

extern void func_800758C8(void *state);
extern void func_80075AEC(void *state);
extern void func_8008204C(void *object);
extern void func_800AACB0(void *list, Actor *actor, int flag);
extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);
extern void func_800BBD78(void *bank, int team, int a, int b, int c);
extern void func_800AA658(void *list, void *slot);

#define VCALL(obj, idx) (obj)->vtbl[idx].fn((char *)(obj) + (obj)->vtbl[idx].offset)
#define VCALL1(obj, idx, a) (obj)->vtbl[idx].fn((char *)(obj) + (obj)->vtbl[idx].offset, a)

void func_800AD6D8(unsigned char *state)
{
    Actor *actor;

    func_800758C8(state);
    func_800AC334(state + 32392);
    func_800ADC1C(state + 32392);
    func_800AC334(state + 7244);
    func_8008204C(state + 7244);
    actor = *(Actor **)(state + 11704);
    if (actor != 0) {
        unsigned char slot = actor->slot;
        if (slot != 8) {
            SlotEntry *entry = &D_800FC270[slot];
            *(int *)(entry->data + 72) = 0;
        }
        func_80075AEC(state);
        func_800BBD78(D_800F2AD8, actor->team, 0, 0, 5);
        func_800BBD78(D_800F2AD8, actor->team, 1, 0, 2);
        func_800AACB0(D_800F26E0, actor, 0);
        VCALL(actor, 3);
        VCALL1(actor, 1, 2);
        func_800AA658(D_800F2758, state + 11704);
    }
}
