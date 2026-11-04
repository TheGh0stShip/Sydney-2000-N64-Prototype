#ifndef LEAF_NAME
#define LEAF_NAME configureAudioTransition
#endif

typedef signed int s32;
typedef unsigned int u32;

void LEAF_NAME(s32 firstValue, s32 secondValue) {
    if (*(volatile u32 *)0x80064F7C == 0) {
        return;
    }

    if (secondValue < 0) {
        secondValue = *(volatile s32 *)0x800F1B4C;
    }
    if (firstValue < 0) {
        firstValue = *(volatile s32 *)0x800F1B4C;
    }

    if (firstValue < secondValue) {
        *(volatile u32 *)0x80064F60 = 1;
        *(volatile u32 *)0x80064F6C = 1;
        *(volatile u32 *)0x80064F74 = 1;
        *(volatile s32 *)0x80064F78 = secondValue;
    } else {
        *(volatile u32 *)0x80064F60 = 1;
        *(volatile u32 *)0x80064F70 = 1;
        *(volatile s32 *)0x80064F78 = 0;
        *(volatile s32 *)0x80064F74 = *(volatile s32 *)0x800F1B4C;
    }
}
