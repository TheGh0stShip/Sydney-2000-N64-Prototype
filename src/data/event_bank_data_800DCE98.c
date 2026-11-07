/* Initialized data retained at ROM 0xDCE98. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800DCE98[2] __attribute__((section(".data"))) = {
    0x3F800000, 0x46FFFDFF,
};
