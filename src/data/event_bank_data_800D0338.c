/* Initialized overlay/runtime data at ROM 0xD0338. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800D0338[16] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x80070C58, 0x80070C6C, 0x80070B98, 0x80070CF0, 0x80070CDC, 0x80070CF0,
    0x80070BD0, 0x80070CF0, 0x80070CF0, 0x80070CF0, 0x80070CF0, 0x80070CF0, 0x00010306, 0x42C80000,
};
