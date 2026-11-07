/* Initialized data retained at ROM 0x89388. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80089388[18] __attribute__((section(".data"))) = {
    0x80071F28, 0x80071F28, 0x80071EE0, 0x80071F28, 0x80071F28, 0x80071F38, 0x80072038, 0x800720E4,
    0x80071FD8, 0x80072038, 0x80072038, 0x80072094, 0x800721DC, 0x800721DC, 0x80072294, 0x800721DC,
    0x800721DC, 0x8007222C,
};
