/* Event-state lookup table at ROM 0xD3428. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800D3428[14] __attribute__((section(".data"))) = {
    0, 0, 2, 4, 0, 3, 8, 0, 4, 1, 0, 5, 2, 0,
};
