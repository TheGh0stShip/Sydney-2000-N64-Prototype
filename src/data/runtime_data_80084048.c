/* Initialized data retained at ROM 0x127938. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80084048[22] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x8008F738, 0x00000000, 0x800AC37C, 0x00000000, 0x800AC334,
    0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x8008DE48, 0x00000000, 0x8008F730,
    0x00000000, 0x00000000, 0x53544143, 0x4B000000, 0x73746163, 0x6B3F0000,
};
