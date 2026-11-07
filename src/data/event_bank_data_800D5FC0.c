/* Initialized data retained at ROM 0xD5FC0. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800D5FC0[12] __attribute__((section(".data"))) = {
    0x800770B8, 0x800770B8, 0x800770D8, 0x800770D8, 0x800770D8, 0x800770CC, 0x00000000, 0x00000000,
    0x80076188, 0x8007619C, 0x00000000, 0x00000000,
};
