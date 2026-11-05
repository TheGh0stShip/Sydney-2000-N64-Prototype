/* Initialized overlay/runtime data at ROM 0x129758. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80085E68[24] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x3F800000, 0x00000001, 0x00000002, 0x00000000, 0x3F800000, 0x3F000000,
    0x3F800000, 0x3F000000, 0x3B800000, 0x3B800000, 0x3F800000, 0x3F800000, 0x3B800000, 0x3B800000,
    0x3B800000, 0x3B800000, 0x3F800000, 0x3B800000, 0x3B800000, 0x3F800000, 0x40800000, 0x3F000000,
};
