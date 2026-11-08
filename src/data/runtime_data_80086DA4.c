/* Initialized data retained at ROM 0x12A694. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80086DA4[5] __attribute__((section(".data"))) = {
    0x41F00000, 0x3B800000, 0x3F800000, 0x47800000, 0x39800000,
};
