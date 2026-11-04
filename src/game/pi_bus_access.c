#include <ultra64.h>

void func_80028328(u32* address, u32 value) {
    while (*(volatile u32*)0xA4600010 & 3) {
    }
    *address = value;
}

u32 func_80028360(volatile u32* address) {
    while (*(volatile u32*)0xA4600010 & 3) {
    }
    return *address;
}
