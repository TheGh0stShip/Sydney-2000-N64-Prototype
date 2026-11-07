/* Initialized data retained at ROM 0xC8158. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800C8158[2] __attribute__((section(".data"))) = {
    0x45F00000, 0x3F800000,
};
