#include <ultra64.h>

void osSpTaskStartGo(OSTask* task) {
    while (__osSpDeviceBusy()) {
    }
    __osSpSetStatus(SP_SET_INTR_BREAK | SP_CLR_SSTEP | SP_CLR_BROKE |
                    SP_CLR_HALT);
}
