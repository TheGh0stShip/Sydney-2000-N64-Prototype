/* Initialized overlay/runtime data at ROM 0x15A30C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_padding_800B6A1C[1] __attribute__((section(".data"))) = {
    0x00000000,
};
