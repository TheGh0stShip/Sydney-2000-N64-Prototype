/* Initialized data retained at ROM 0xA2060. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A2060[6] __attribute__((section(".data"))) = {
    0x80071BDC, 0x80071BDC, 0x80071B98, 0x80071BDC, 0x80071BDC, 0x80071BE8,
};
