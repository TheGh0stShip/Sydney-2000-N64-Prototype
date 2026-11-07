/* Initialized data retained at ROM 0x82848. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80082848[10] __attribute__((section(".data"))) = {
    0xC051B573, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x8007743C, 0x800762BC, 0x800762D0,
    0x00000000, 0x00000000,
};
