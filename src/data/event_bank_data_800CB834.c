/* Initialized data retained at ROM 0xCB834. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800CB834[16] __attribute__((section(".data"))) = {
    0x41F00000, 0x3B800000, 0x4F000000, 0x42C80000, 0x4F000000, 0x4F000000, 0x42C80000, 0x4F000000,
    0x3F4CCCCD, 0x3F666666, 0x4F000000, 0x42C80000, 0x4F000000, 0x4F000000, 0x42C80000, 0x4F000000,
};
