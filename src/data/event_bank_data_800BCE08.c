/* Initialized data retained at ROM 0xBCE08. */
typedef unsigned int u32;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];

u32 event_bank_data_800BCE08[24] __attribute__((section(".data"))) = {
    0x80070D78, 0x80070E58, 0x80070F14, 0x800712D4, 0x800713B8, 0x800713C4, 0x8007150C, 0x3CA3D70A,
    0x3C23D70A, 0x3C23D70A, 0xBC23D70A, 0x3C23D70A, 0x3F800000, 0x3F8A3D71, 0x3F70A3D7, 0x3F333333,
    0x41F00000, 0x3B800000, 0x42C80000, 0x42700000, 0x41F00000, 0x3FA66666, 0x3D0EFA34, 0x40C90FDB,
};
