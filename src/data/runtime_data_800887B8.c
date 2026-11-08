/* Initialized data retained at ROM 0x12C0A8. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_800887B8[15] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x4D495445, 0x4D5F4241, 0x52000000, 0x41200000, 0x3F800000, 0xBF800000,
    0x42E00000, 0x42440000, 0x41200000, 0x3F800000, 0xBF800000, 0x42740000, 0x44044000,
};
