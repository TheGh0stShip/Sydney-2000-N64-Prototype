/* Initialized data retained at ROM 0x105174. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80105174[23] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x8007BED4, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800ADC5C, 0x00000000, 0x800B97D4, 0x00000000, 0x8007BF08, 0x00000000,
    0x8007BF00, 0x00000000, 0x800ADC38, 0x00000000, 0x800ADC1C, 0x00000000, 0x8007BEF8,
};
