#include <ultra64.h>

#define SI_DRAM_ADDR_REG 0xA4800000
#define SI_PIF_ADDR_RD64B_REG 0xA4800004
#define SI_PIF_ADDR_WR64B_REG 0xA4800010
#define PIF_RAM_START 0x1FC007C0
#define PIF_RAM_SIZE 0x40

static __inline__ s32 siDeviceBusy(void) {
    register u32 status = *(volatile u32*)0xA4800018;
    if (status & 3) {
        return 1;
    }
    return 0;
}

s32 __osSiRawStartDma(s32 direction, void* dramAddr) {
    if (siDeviceBusy()) {
        return -1;
    }
    if (direction == OS_WRITE) {
        osWritebackDCache(dramAddr, PIF_RAM_SIZE);
    }
    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, PIF_RAM_START);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, PIF_RAM_START);
    }
    if (direction == OS_READ) {
        osInvalDCache(dramAddr, PIF_RAM_SIZE);
    }
    return 0;
}
