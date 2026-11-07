/* Initialized data retained at ROM 0x90684. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80090684[1] __attribute__((section(".data"))) = {
    0x42C80000,
};
