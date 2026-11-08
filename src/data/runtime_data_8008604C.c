/* Initialized data retained at ROM 0x12993C. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_8008604C[1] __attribute__((section(".data"))) = {
    0x00000000,
};
