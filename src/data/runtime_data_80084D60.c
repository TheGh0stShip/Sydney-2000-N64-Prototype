/* Initialized data retained at ROM 0x128650. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 runtime_data_80084D60[24] __attribute__((section(".data"))) = {
    0x53544143, 0x4B000000, 0x73746163, 0x6B3F0000, 0x4E455446, 0x41434553, 0x00000000, 0x484A4C4F,
    0x474F0000, 0x3CCCCCCD, 0x440A31E0, 0x41A913E6, 0x44E0B320, 0x43D7B054, 0x44288B96, 0x44E6ECE9,
    0x44DA7957, 0x3F800000, 0x3DCCCCCD, 0x3E99999A, 0x3F666666, 0x00000000, 0x3FC1EB85, 0x1EB851EC,
};
