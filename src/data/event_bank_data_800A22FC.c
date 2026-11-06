/* Initialized overlay/runtime data at ROM 0xA22FC. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A22FC[5] __attribute__((section(".data"))) = {
    0x50415448, 0x535F5F56, 0x44545249, 0x504C455F, 0x50544200,
};
