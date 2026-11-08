/* Initialized data retained at ROM 0xA259C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A259C[17] __attribute__((section(".data"))) = {
    0x41200000, 0x80075960, 0x800759B0, 0x80075A00, 0x80075A50, 0x80075AA0, 0x80075AA0, 0x80075AA0,
    0x80075AA0, 0x80075B68, 0x80075BEC, 0x80075C70, 0x80075CF4, 0x80075D78, 0x80075D78, 0x80075D78,
    0x80075D78,
};
