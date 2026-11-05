/* Initialized overlay/runtime data at ROM 0x17E5F4. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_padding_800DAD04[3] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000,
};
