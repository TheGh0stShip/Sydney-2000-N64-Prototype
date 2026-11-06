/* Initialized overlay/runtime data at ROM 0x70800. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80070800[4] __attribute__((section(".data"))) = {
    0x00000000, 0x800738B0, 0x00000000, 0x00000000,
};
