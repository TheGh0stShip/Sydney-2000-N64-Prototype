/* Initialized data retained at ROM 0x11C060. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8011C060[25] __attribute__((section(".data"))) = {
    0xBF0CCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53544143, 0x4B000000, 0x73746163, 0x6B3F0000,
    0x80080B04, 0x80080B4C, 0x80080C4C, 0x80080D2C, 0x80080DBC, 0x80080E14, 0x3E20D97C, 0x3BF1EAEF,
    0x3F30EF3C,
};
