#include "sydney_types.h"

/* Constructor of a menu screen object holding several groups of entries and option cards (C++). */
struct Object {
    s32 unk_00;
    u8 pad04[0xAC];
    u8 unk_B0;
    u8 unk_B1;
    u8 padB2[2];
    virtual void v0() __asm__("func_80000010");
};

struct Entry : Object {
    u8 padB8[0x1C];
    Entry() __asm__("func_800ADE10");
};

struct Slot {
    u8 pad[0xD4];
    Slot() __asm__("func_800CE3A8");
};

struct Card : Entry {
    s16 unk_D4;
    s16 unk_D6;
    s16 unk_D8;
    u8 padDA[2];
    Card() {
        unk_00 = 0x3E;
        unk_B0 = 1;
        unk_D6 = -1;
        unk_D8 = -1;
        unk_D4 = 4;
    }
    virtual void v0() __asm__("func_80000014");
};

struct Screen : Entry {
    Slot slots[8];
    u8 pad774[0x10];
    Card card0;
    Card card1;
    Card card2;
    Card card3;
    Card cards[7];
    Card extra[5];
    u8 pad1544[0x14];
    Entry groupA[5];
    Entry groupB[5];
    Entry groupC[5];
    Entry unk_21C4;
    Entry unk_2298;
    Entry unk_236C;
    Screen();
    virtual void v0() __asm__("func_80000018");
};

Screen::Screen() {
    unk_00 = 0x47;
    unk_B1 = 1;
}
