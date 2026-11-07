/* Initialized data retained at ROM 0x96600. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80096600[20] __attribute__((section(".data"))) = {
    0x80071D14, 0x80071C08, 0x80071C08, 0x80071C20, 0x80071D14, 0x80071D14, 0x80071C3C, 0x80071C58,
    0x80071D14, 0x80071D14, 0x80071D14, 0x80071D14, 0x80071C74, 0x80071D14, 0x80071D14, 0x80071D14,
    0x80071D14, 0x80071CA0, 0x80071CD8, 0x00000000,
};
