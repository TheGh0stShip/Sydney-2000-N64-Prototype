/* Initialized data retained at ROM 0x11FBD4. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8011FBD4[19] __attribute__((section(".data"))) = {
    0x3DCCCCCD, 0x00000000, 0x00000000, 0x00000000, 0x80081890, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x8008182C, 0x00000000,
    0x80081824, 0x00000000, 0x00000000,
};
