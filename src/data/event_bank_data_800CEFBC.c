/* Initialized data retained at ROM 0xCEFBC. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800CEFBC[21] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80070B0C, 0x80070B20, 0x80070A38,
    0x80070BA4, 0x80070B90, 0x80070BA4, 0x80070A84, 0x80070BA4, 0x80070BA4, 0x80070BA4, 0x80070BA4,
    0x80070BA4, 0xBF800000, 0x3DCCCCCD, 0x3FD1B574, 0x41831168,
};
