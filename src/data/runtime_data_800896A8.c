/* Initialized data retained at ROM 0x12CF98. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_800896A8[7] __attribute__((section(".data"))) = {
    0x44168000, 0x41A00000, 0x3F800000, 0x3F800000, 0x3D9D89CE, 0x3C23D70A, 0x45F00000,
};
