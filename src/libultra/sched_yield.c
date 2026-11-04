#include <sched.h>

#define OS_SC_YIELD 0x0010

void __scYield(OSSched* sched) {
    if (sched->curRSPTask->list.t.type == M_GFXTASK) {
        sched->curRSPTask->state |= OS_SC_YIELD;
        osSpTaskYield();
    }
}
