/* Initialized data retained at ROM 0xD5B78. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800D5B78[12] __attribute__((section(".data"))) = {
    0x41F00000, 0x3B800000, 0x41F00000, 0x3B800000, 0x80072490, 0x80072490, 0x8007264C, 0x80072534,
    0x80072584, 0x80072574, 0x41F00000, 0x3B800000,
};
