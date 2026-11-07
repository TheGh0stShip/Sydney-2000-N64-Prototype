/* Initialized data retained at ROM 0x128764. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80084E74[23] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800A1664, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800ADC5C, 0x00000000, 0x800AC178, 0x00000000, 0x800A1240, 0x00000000,
    0x800A1398, 0x00000000, 0x800ADC38, 0x00000000, 0x800ADC1C, 0x4F000000, 0x00000000,
};
