/* Initialized overlay/runtime data at ROM 0x1197B8. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_801197B8[18] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x8007F1A4, 0x00000000, 0x800AC37C, 0x00000000, 0x800AC334,
    0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x8007F198, 0x00000000, 0x8007F190,
    0x00000000, 0x00000000,
};
