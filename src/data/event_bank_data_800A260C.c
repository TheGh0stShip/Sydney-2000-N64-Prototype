/* Initialized data retained at ROM 0xA260C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800A260C[17] __attribute__((section(".data"))) = {
    0x00000000, 0x800762D4, 0x80076214, 0x80076234, 0x80076254, 0x80076274, 0x80076294, 0x3F451EB8,
    0x3F490FD9, 0x3DC49808, 0x3E8A8262, 0x3F490FD9, 0x3DC49808, 0x3E8A8262, 0x3F490FD9, 0x3DC49808,
    0x3E8A8262,
};
