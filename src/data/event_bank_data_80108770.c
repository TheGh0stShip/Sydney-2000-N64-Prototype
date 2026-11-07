/* Initialized data retained at ROM 0x108770. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80108770[24] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x8007B4F8, 0x00000000, 0x800AC37C, 0x00000000, 0x800AC334,
    0x00000000, 0x800ADC5C, 0x00000000, 0x800B97D4, 0x00000000, 0x8007B52C, 0x00000000, 0x8007B524,
    0x00000000, 0x800ADC38, 0x00000000, 0x800ADC1C, 0x00000000, 0x8007B51C, 0x00000000, 0x00000000,
};
