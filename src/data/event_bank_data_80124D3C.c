/* Initialized data retained at ROM 0x124D3C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80124D3C[25] __attribute__((section(".data"))) = {
    0x3E800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80083BA8, 0x00000000,
    0x800AC37C, 0x00000000, 0x800AC334, 0x00000000, 0x800ADC5C, 0x00000000, 0x800B97D4, 0x00000000,
    0x80083BDC, 0x00000000, 0x80083BD4, 0x00000000, 0x800ADC38, 0x00000000, 0x800ADC1C, 0x00000000,
    0x80083BCC,
};
