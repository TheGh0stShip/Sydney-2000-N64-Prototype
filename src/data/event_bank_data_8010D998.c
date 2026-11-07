/* Initialized data retained at ROM 0x10D998. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8010D998[10] __attribute__((section(".data"))) = {
    0x40D1B574, 0xC051B573, 0x4051B574, 0x40000000, 0x4F000000, 0xC2031168, 0x41700000, 0x437F0000,
    0x4F000000, 0xC051B573,
};
