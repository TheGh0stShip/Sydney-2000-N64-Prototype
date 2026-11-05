/* Initialized overlay/runtime data at ROM 0xA1418. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A1418[13] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x800707E0, 0x80070808, 0x80070830, 0x80070854, 0x80070878, 0x8007089C,
    0x800708C4, 0x800708E8, 0x8007090C, 0x80070930, 0x80070954,
};
