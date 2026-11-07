/* Initialized data retained at ROM 0x12218C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_8012218C[21] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80081DC8, 0x00000000, 0x800AC37C, 0x00000000,
    0x800AC334, 0x00000000, 0x800AC1B8, 0x00000000, 0x800AC178, 0x00000000, 0x800AC218, 0x00000000,
    0x80082FEC, 0x3F800000, 0x42790779, 0x421D4817, 0x41831168,
};
