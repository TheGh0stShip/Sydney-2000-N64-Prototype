typedef struct {
    short delta;
    short index;
    void (*func)(void *self, ...);
} VEntry;

typedef struct {
    unsigned char pad[56];
    float value;
} Slot;

extern Slot *D_800FC270;
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern void func_8007716C(void *object);
extern void func_800ADC1C(void *object);
extern void func_800BBD78(void *list, int id, int a, int b, int c);
extern void func_800AACB0(void *list, void *object, int a);
extern void func_800AA658(void *list, void *slot);

#define VTABLE(p) (*(VEntry **)((unsigned char *)(p) + 180))

void func_800B48E4(unsigned char *object, int keep)
{
    unsigned char *sub;
    unsigned char *actor;

    func_8007716C(object);
    sub = object + 21076;
    VTABLE(sub)[3].func(sub + VTABLE(sub)[3].delta);
    sub[176] = 0;
    func_800ADC1C(sub);
    actor = *(unsigned char **)(object + 21292);
    if (actor != 0) {
        if (actor[426] == 1) {
            Slot *slot = &D_800FC270[actor[424]];
            slot->value = *(float *)(actor + 420);
        }
        func_800BBD78(D_800F2AD8, (signed char)actor[427], 0, 0, 5);
        func_800BBD78(D_800F2AD8, (signed char)actor[427], 1, 0, 2);
        func_800AACB0(D_800F26E0, actor, 0);
        VTABLE(actor)[3].func(actor + VTABLE(actor)[3].delta);
        VTABLE(actor)[1].func(actor + VTABLE(actor)[1].delta, 2);
        if ((keep & 0xff) == 0) {
            func_800AA658(D_800F2758, object + 21292);
        }
    }
}
