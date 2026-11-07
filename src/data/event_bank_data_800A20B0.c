/* Initialized data retained at ROM 0xA20B0. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A20B0[5] __attribute__((section(".data"))) = {
    0x800726F4, 0x80072914, 0x80072314, 0x80072914, 0x80072894,
};
