/* Initialized data retained at ROM 0x12222C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8012222C[9] __attribute__((section(".data"))) = {
    0x00000000, 0x80083A98, 0x80083A48, 0x80083A48, 0x80083A98, 0x80083A68, 0x40490FDB, 0x00000000,
    0x00000000,
};
