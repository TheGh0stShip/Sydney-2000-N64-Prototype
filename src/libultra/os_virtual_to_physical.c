#include "PR/os_internal.h"
#include "PR/R4300.h"
#include "PRinternal/osint.h"

u32 osVirtualToPhysical(void *address) {
    if (IS_KSEG0(address)) {
        return K0_TO_PHYS(address);
    } else if (IS_KSEG1(address)) {
        return K1_TO_PHYS(address);
    } else {
        return __osProbeTLB(address);
    }
}
