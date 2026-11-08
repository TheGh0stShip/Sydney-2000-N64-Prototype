/* Initialized data retained at ROM 0x12BEA4. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_800885B4[15] __attribute__((section(".data"))) = {
    0x3F800000, 0x41200000, 0x00000000, 0x4D495445, 0x4D5F4241, 0x52000000, 0x3F800000, 0x425C0000,
    0xC0400000, 0x41300000, 0x3F800000, 0x53544143, 0x4B000000, 0x73746163, 0x6B3F0000,
};
