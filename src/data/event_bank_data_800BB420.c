/* Initialized data retained at ROM 0xBB420. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800BB420[20] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x80072338, 0x00000000, 0x800AC37C, 0x00000000, 0x800AC334,
    0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x80070A30, 0x00000000, 0x80072198,
    0x42700000, 0x41F00000, 0x45F00000, 0x00000000,
};
