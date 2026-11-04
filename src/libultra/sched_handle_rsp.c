#include <sched.h>

#define OS_SC_YIELD 0x0010
#define OS_SC_YIELDED 0x0020
#define OS_SC_XBUS (OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP)

extern s32 __scTaskComplete(OSSched* sched, OSScTask* task);
extern s32 __scSchedule(OSSched* sched, OSScTask** sp, OSScTask** dp,
                        s32 availRCP);
extern void __scExec(OSSched* sched, OSScTask* sp, OSScTask* dp);

void __scHandleRSP(OSSched* sched) {
    OSScTask* task;
    OSScTask* sp = 0;
    OSScTask* dp = 0;
    s32 state;

    task = sched->curRSPTask;
    sched->curRSPTask = 0;

    if ((task->state & OS_SC_YIELD) && osSpTaskYielded(&task->list)) {
        task->state |= OS_SC_YIELDED;
        if ((task->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
            task->next = sched->gfxListHead;
            sched->gfxListHead = task;
            if (sched->gfxListTail == 0) {
                sched->gfxListTail = task;
            }
        }
    } else {
        task->state &= ~OS_SC_NEEDS_RSP;
        __scTaskComplete(sched, task);
    }

    state = ((sched->curRSPTask == 0) << 1) | (sched->curRDPTask == 0);
    if (__scSchedule(sched, &sp, &dp, state) != state) {
        __scExec(sched, sp, dp);
    }
}
