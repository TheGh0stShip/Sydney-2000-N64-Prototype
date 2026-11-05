/* Initialized overlay/runtime data at ROM 0x6DF34. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 ceremony_data_80075858[3] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x00000000,
};
