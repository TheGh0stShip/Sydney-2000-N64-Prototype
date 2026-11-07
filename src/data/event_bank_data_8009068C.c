/* Initialized data retained at ROM 0x9068C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8009068C[2] __attribute__((section(".data"))) = {
    0x486A7041, 0x74680000,
};
