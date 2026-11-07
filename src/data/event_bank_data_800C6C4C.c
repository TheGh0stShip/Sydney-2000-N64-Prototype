/* Initialized data retained at ROM 0xC6C4C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800C6C4C[21] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80071C4C, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x80070980, 0x00000000,
    0x80071C44, 0x3F800000, 0x00000000, 0x00000000, 0x00000000,
};
