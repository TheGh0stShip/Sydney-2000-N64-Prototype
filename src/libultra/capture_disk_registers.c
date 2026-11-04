#ifndef LEAF_NAME
#define LEAF_NAME captureDiskRegisters
#endif

#ifndef FIRST_STATUS_NAME
#define FIRST_STATUS_NAME firstDiskStatus
#endif

#ifndef SECOND_STATUS_NAME
#define SECOND_STATUS_NAME secondDiskStatus
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 FIRST_STATUS_NAME[];
extern u8 SECOND_STATUS_NAME[];

void LEAF_NAME(void) {
    u32 first = *(volatile u32 *)0xA4600014;
    u32 second = *(volatile u32 *)0xA4600018;
    u32 third = *(volatile u32 *)0xA460001C;
    u32 fourth = *(volatile u32 *)0xA4600020;
    u32 fifth = *(volatile u32 *)0xA4600024;
    u32 sixth = *(volatile u32 *)0xA4600028;
    u32 seventh = *(volatile u32 *)0xA460002C;
    u32 eighth = *(volatile u32 *)0xA4600030;

    FIRST_STATUS_NAME[0] = 7;
    SECOND_STATUS_NAME[0] = 7;
    FIRST_STATUS_NAME[1] = first;
    FIRST_STATUS_NAME[4] = second;
    FIRST_STATUS_NAME[2] = third;
    FIRST_STATUS_NAME[3] = fourth;
    SECOND_STATUS_NAME[1] = fifth;
    SECOND_STATUS_NAME[4] = sixth;
    SECOND_STATUS_NAME[2] = seventh;
    SECOND_STATUS_NAME[3] = eighth;
}
