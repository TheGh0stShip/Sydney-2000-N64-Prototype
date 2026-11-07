/* Initialized data retained at ROM 0x129C98. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_800863A8[8] __attribute__((section(".data"))) = {
    0x3F800000, 0x4F000000, 0x4F000000, 0x4F000000, 0x4F000000, 0x4F000000, 0x4F000000, 0x3D088889,
};
