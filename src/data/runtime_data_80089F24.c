/* Initialized data retained at ROM 0x12D814. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80089F24[21] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800D3460, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800ADD9C, 0x00000000, 0x800AC178, 0x00000000, 0x800D334C, 0x00000000,
    0x800D3284, 0x00000000, 0x800ADC38, 0x00000000, 0x800ADC1C,
};
