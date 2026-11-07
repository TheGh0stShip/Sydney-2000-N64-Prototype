/* Initialized data retained at ROM 0xBCDC8. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800BCDC8[16] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x80070C5C, 0x80070C70, 0x80070A9C, 0x80070CEC, 0x80070CD8, 0x80070CEC,
    0x80070AD4, 0x80070CEC, 0x80070CEC, 0x80070CEC, 0x80070CEC, 0x80070CEC, 0x00010306, 0x00000000,
};
