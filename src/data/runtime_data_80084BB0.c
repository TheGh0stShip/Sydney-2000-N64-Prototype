/* Initialized data retained at ROM 0x1284A0. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80084BB0[8] __attribute__((section(".data"))) = {
    0x41F00000, 0x40084F8C, 0xC320B8DE, 0x41F00000, 0x43800000, 0x40084F8C, 0x420C3E25, 0x42031168,
};
