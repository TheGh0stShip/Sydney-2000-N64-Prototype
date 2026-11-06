/* Initialized overlay/runtime data at ROM 0x73638. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_80073638[21] __attribute__((section(".data"))) = {
    0x00000000, 0x00000000, 0x0005FA00, 0x00061800, 0x0005BE00, 0x0007BC00, 0x00054600, 0x00070800,
    0x00070800, 0x00030C00, 0x00074400, 0x0004EC00, 0x0006EA00, 0x0006EA00, 0x00070800, 0x0006EA00,
    0x0006CC00, 0x0005A000, 0x0004B000, 0x0003DE00, 0x00054600,
};
