/* Initialized data retained at ROM 0xDCEA4. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800DCEA4[1] __attribute__((section(".data"))) = {
    0x00000000,
};
