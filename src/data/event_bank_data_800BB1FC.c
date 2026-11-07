/* Initialized data retained at ROM 0xBB1FC. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800BB1FC[19] __attribute__((section(".data"))) = {
    0x41831168, 0x416BEC21, 0x00000000, 0x00000000, 0x00000000, 0x80070C4C, 0x80070C60, 0x80070A8C,
    0x80070D00, 0x80070CEC, 0x80070D00, 0x80070AC4, 0x80070D00, 0x80070D00, 0x80070D00, 0x80070D00,
    0x80070D00, 0x00010306, 0x00000000,
};
