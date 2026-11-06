/* Initialized overlay/runtime data at ROM 0xB6CEC. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800B6CEC[25] __attribute__((section(".data"))) = {
    0x41F00000, 0x3B800000, 0x42C80000, 0x40A00000, 0x40200000, 0x00000000, 0x00000000, 0x00000000,
    0x80071950, 0x00000000, 0x800AC37C, 0x00000000, 0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000,
    0x800AC178, 0x00000000, 0x80070980, 0x00000000, 0x800718D8, 0x45F00000, 0x3F800000, 0x00000000,
    0x00000000,
};
