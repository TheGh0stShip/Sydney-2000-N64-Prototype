/* Initialized overlay/runtime data at ROM 0xCB874. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800CB874[19] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80071E80, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x800709A0, 0x00000000,
    0x80071E78, 0x00000000, 0x00000000,
};
