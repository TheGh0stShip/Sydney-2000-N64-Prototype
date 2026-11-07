/* Initialized data retained at ROM 0x11E42C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8011E42C[1] __attribute__((section(".data"))) = {
    0x3F000000,
};
