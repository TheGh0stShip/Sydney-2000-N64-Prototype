/* Initialized data retained at ROM 0x7A65C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8007A65C[2] __attribute__((section(".data"))) = {
    0x3F800000, 0x43FA0000,
};
