/* Initialized data retained at ROM 0x1170D8. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_801170D8[2] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000,
};
