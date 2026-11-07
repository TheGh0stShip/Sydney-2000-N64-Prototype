/* Initialized data retained at ROM 0x12221C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8012221C[3] __attribute__((section(".data"))) = {
    0x3F800000, 0x437F0000, 0x3F800000,
};
