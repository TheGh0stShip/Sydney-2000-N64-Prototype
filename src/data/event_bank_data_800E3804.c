/* Initialized data retained at ROM 0xE3804. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800E3804[12] __attribute__((section(".data"))) = {
    0x3F000000, 0x4096CBE4, 0x00000000, 0x8007AE08, 0x8007AE08, 0x8007AE28, 0x8007AE28, 0x8007AE48,
    0x8007AE08, 0x41F00000, 0x3B800000, 0x45F00000,
};
