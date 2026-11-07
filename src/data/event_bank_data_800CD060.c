/* Initialized data retained at ROM 0xCD060. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800CD060[4] __attribute__((section(".data"))) = {
    0x45F00000, 0x3F800000, 0x00000000, 0x00000000,
};
