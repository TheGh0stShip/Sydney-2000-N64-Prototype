typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self);
} VEntry;

typedef struct Slot {
    char pad00[0xB0];
    unsigned char visible;
    char padB1[0xB4 - 0xB1];
    VEntry *vtable;
    char padB8[0xDC - 0xB8];
} Slot;

typedef struct Arena {
    char pad0000[0xB8];
    int music;
    char pad00BC[0xD8 - 0xBC];
    char camera[0x310 - 0xD8];
    Slot slots[18];
    char pad1288[0x1448 - 0x1288];
    char overlay[0x151C - 0x1448];
    char lightA[0x1548 - 0x151C];
    char lightB[1];
} Arena;

extern char D_800F1AE0[];
extern char D_800F26E0[];
extern char D_800F26F4[];
extern char D_800F2AD8[];
extern char D_800F4D00[];

extern void func_800AB934(void *list, Arena *arena);
extern void func_800A3218(void *p);
extern void func_800A3240(void *p);
extern void func_800BAC24(void);
extern void func_800ADC1C(void *p);
extern void func_800B35F0(Slot *slot);
extern void func_800D52A8(void *p);
extern void func_800DB124(int arg);
extern void func_800BC274(void *p);
extern void func_800AB240(void *p);
extern void func_800AC308(void *p);
extern void func_800AC334(void *p);
extern void func_80017B24(int music);
extern void func_80006A18(void *p);
extern void func_80017A90(unsigned int mask);
extern void func_80014384(void);
extern void func_800137FC(void);

void func_80114D74(Arena *arena) {
    unsigned char i;

    func_800AB934(D_800F26F4, arena);
    func_800A3218(D_800F1AE0);
    func_800A3240(D_800F1AE0);
    func_800BAC24();
    func_800ADC1C(arena->overlay);
    i = 0;
    for (;;) {
        Slot *slot;
        unsigned int off;

        if (i >= 18) {
            break;
        }
        off = i * sizeof(Slot);
        slot = (Slot *)(off + (unsigned int)arena + 0x310);
        slot->vtable[3].fn((char *)slot + slot->vtable[3].delta);
        slot->visible = 0;
        func_800B35F0(&arena->slots[i]);
        i++;
    }
    func_800D52A8(D_800F4D00);
    func_800DB124(1);
    func_800BC274(D_800F2AD8);
    func_800AB240(D_800F26E0);
    func_800AC308(arena);
    func_800AC334(arena->camera);
    func_80017B24(arena->music);
    func_80006A18(arena->lightA);
    func_80006A18(arena->lightB);
    func_80017A90(0x80000000);
    func_80014384();
    func_800137FC();
}
