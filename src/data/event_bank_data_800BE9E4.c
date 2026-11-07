/* Initialized data retained at ROM 0xBE9E4. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800BE9E4[13] __attribute__((section(".data"))) = {
    0xC2F5C0A3, 0x40831168, 0x00000000, 0x41F00000, 0x00000000, 0x39800000, 0x3FA66666, 0x41C49A1C,
    0xBE36DDB7, 0xBDB6DDB7, 0x00000000, 0x41F00000, 0x00000000,
};
