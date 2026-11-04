#ifndef LEAF_NAME
#define LEAF_NAME initializeSlotState
#endif

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct SlotTemplate {
    u32 words[4];
} SlotTemplate;

typedef struct SlotState {
    u32 index;
    u32 count;
    u32 recordFlags[3];
    u32 padding14;
    SlotTemplate records[3];
    u32 firstSlots[8];
    u32 secondSlots[8];
    u32 thirdSlots[8];
} SlotState;

void LEAF_NAME(SlotState *state) {
    register SlotState *statePointer __asm__("$4") = state;
    register u32 index __asm__("$3");
    register u8 *record __asm__("$6");
    register u8 *flags __asm__("$5");
    register u8 *templatePage __asm__("$7");
    register u8 *template __asm__("$11");

    index = 0;
    record = (u8 *)statePointer;
    flags = (u8 *)statePointer;
    templatePage = (u8 *)0x80040000;
    __asm__("" : "=r"(index), "=r"(record), "=r"(flags), "=r"(templatePage)
            : "0"(index), "1"(record), "2"(flags), "3"(templatePage));
    __asm__("" : "=r"(statePointer) : "0"(statePointer));
    statePointer->index = 0;
    statePointer->count = 0;
    do {
        *(u32 *)(flags + 8) = 0;
        template = templatePage + 0x3D38;
        __asm__("" : "=r"(template) : "0"(template));
        *(SlotTemplate *)(record + 24) = *(SlotTemplate *)template;
        record += 16;
        index++;
        flags += 4;
    } while (index < 3);
    index = 0;
    do {
        statePointer->firstSlots[0] = 0;
        statePointer->secondSlots[0] = 0;
        statePointer->thirdSlots[0] = 0;
        index++;
        statePointer = (SlotState *)((u8 *)statePointer + 4);
    } while (index < 8);
}
