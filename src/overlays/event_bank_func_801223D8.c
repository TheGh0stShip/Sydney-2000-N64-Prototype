typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Slot {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0xDC - 0xB8];
} Slot;

typedef struct Marker {
    char pad00[0xB4];
    VEntry *vtable;
    char padB8[0xD4 - 0xB8];
} Marker;

typedef struct Stage {
    char pad0000[0xB4];
    VEntry *vtable;
    char pad00B8[0xD8 - 0xB8];
    char camera[0x650 - 0xD8];
    Slot slots[10];
    char pad0EE8[0xF20 - 0xEE8];
    char hud[0x10F0 - 0xF20];
    char label[0x11C8 - 0x10F0];
    char overlay[0x1384 - 0x11C8];
    char panel[0x2598 - 0x1384];
    char listB[0x2808 - 0x2598];
    char listA[0x2B78 - 0x2808];
    char board[0x33F4 - 0x2B78];
    char banner[0x34D8 - 0x33F4];
    Marker markers[2];
    char pad3680[0x3684 - 0x3680];
    char effects[1];
} Stage;

extern VEntry D_80081B80[];

extern void func_800CA968(void *p, int flags);
extern void func_800ADE84(void *p, int flags);
extern void func_800C943C(void *p, int flags);
extern void func_800CA094(void *p, int flags);
extern void func_800CA73C(void *p, int flags);
extern void func_800BA1B4(void *p, int flags);
extern void func_800BB1F4(void *p, int flags);
extern void func_800D3460(void *p, int flags);
extern void func_800AC3A4(Stage *stage, int flags);

#define DESTROY_ARRAY(arr, n, T)                                            \
    if ((arr) != 0) {                                                       \
        T *p = &(arr)[n];                                                   \
        if ((arr) != p) {                                                   \
            T *begin = (arr);                                               \
            do {                                                            \
                p--;                                                        \
                p->vtable[1].fn((char *)p + p->vtable[1].delta, 2);         \
            } while (begin != p);                                           \
        }                                                                   \
    }

void func_801223D8(Stage *stage, int flags) {
    stage->vtable = D_80081B80;
    func_800CA968(stage->effects, 2);
    DESTROY_ARRAY(stage->markers, 2, Marker)
    func_800ADE84(stage->banner, 2);
    func_800C943C(stage->board, 2);
    func_800CA094(stage->listA, 2);
    func_800CA094(stage->listB, 2);
    func_800CA73C(stage->panel, 2);
    func_800BA1B4(stage->overlay, 2);
    func_800ADE84(stage->label, 2);
    func_800BB1F4(stage->hud, 2);
    DESTROY_ARRAY(stage->slots, 10, Slot)
    func_800D3460(stage->camera, 2);
    func_800AC3A4(stage, flags);
}
