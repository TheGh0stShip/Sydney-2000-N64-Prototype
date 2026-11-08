/* Initialized data retained at ROM 0x12F074. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_8008B784[17] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800E45D8, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x800DEF98, 0x00000000,
    0x800E3D38,
};
