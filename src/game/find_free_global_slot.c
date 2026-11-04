#ifndef LEAF_NAME
#define LEAF_NAME findFreeGlobalSlot
#endif

#ifndef STATE_NAME
#define STATE_NAME state
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 index;
    u32 count;
    u8 padding08[0x80];
    void *slots[8];
} SlotState;

extern SlotState STATE_NAME;

u32 LEAF_NAME(void) {
    register u8 *stateBase __asm__("$3");
    register SlotState *slotState __asm__("$4");
    u32 index;

    stateBase = (u8 *)0x80040000;
    __asm__("" : "=r"(stateBase) : "0"(stateBase));
    slotState = (SlotState *)(stateBase + 0x3D48);
    __asm__("" : "=r"(slotState) : "0"(slotState));

    if (slotState->count < 8) {
        index = *(u32 *)(stateBase + 0x3D48);
        while (slotState->slots[index] != 0) {
            index = *(volatile u32 *)(stateBase + 0x3D48) + 1;
            *(volatile u32 *)(stateBase + 0x3D48) = index;
        }
        return STATE_NAME.index;
    }
    return 8;
}
