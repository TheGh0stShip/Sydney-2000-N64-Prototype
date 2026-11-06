/* Initialized overlay/runtime data at ROM 0x74154. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80074154[7] __attribute__((section(".data"))) = {
    0x80076514, 0x00000000, 0x00000000, 0x80075C28, 0x80075C4C, 0x00000000, 0x00000000,
};
