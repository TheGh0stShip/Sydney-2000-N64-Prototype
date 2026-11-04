#ifndef LEAF_NAME
#define LEAF_NAME filterActiveSlotMask
#endif

#ifndef SLOTS_NAME
#define SLOTS_NAME slots
#endif

#ifndef ACTIVE_NAME
#define ACTIVE_NAME active
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Slot {
    u32 handle;
    u8 padding[128];
} Slot;

extern Slot SLOTS_NAME[3];
extern u32 ACTIVE_NAME;

void LEAF_NAME(s32 maskValue) {
    u32 mask = (u32)maskValue;

    if (maskValue >= 0) {
        register u32 index __asm__("$3") = 0;
        register u32 bit __asm__("$6") = 1;
        register u8 *slotBase __asm__("$2") = (u8 *)0x80060000;
        register Slot *slot __asm__("$5");

        __asm__("" : "=r"(slotBase) : "0"(slotBase));
        slot = (Slot *)(slotBase - 0x5510);
        __asm__("" : "=r"(index), "=r"(bit), "=r"(slot)
                : "0"(index), "1"(bit), "2"(slot));
        do {
            if (slot->handle == 0) {
                mask &= ~(bit << index);
            }
            index++;
            slot++;
        } while (index < 3);
    }

    if (mask & 0xC0000000U) {
        register u8 *activeBase __asm__("$3") = (u8 *)0x80060000;

        __asm__("" : "=r"(activeBase) : "0"(activeBase));
        *(u32 *)(activeBase - 0x56A8) = 1;
    }
    if (mask & 0x20000000U) {
        register u8 *activeBase __asm__("$3") = (u8 *)0x80060000;

        __asm__("" : "=r"(activeBase) : "0"(activeBase));
        *(u32 *)(activeBase - 0x56A8) = 1;
    }
}
