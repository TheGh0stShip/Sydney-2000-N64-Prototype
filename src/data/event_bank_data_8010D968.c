/* Initialized data retained at ROM 0x10D968. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8010D968[4] __attribute__((section(".data"))) = {
    0x80000000, 0x41F00000, 0x3B800000, 0x45F00000,
};
