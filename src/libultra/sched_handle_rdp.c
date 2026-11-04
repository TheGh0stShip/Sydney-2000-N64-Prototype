#include <sched.h>

extern s32 __scTaskComplete(OSSched* sched, OSScTask* task);
extern s32 __scSchedule(OSSched* sched, OSScTask** sp, OSScTask** dp,
                        s32 availRCP);
extern void __scExec(OSSched* sched, OSScTask* sp, OSScTask* dp);

void __scHandleRDP(OSSched* sched) {
    OSScTask* task;
    OSScTask* sp = 0;
    OSScTask* dp = 0;
    s32 state;

    task = sched->curRDPTask;
    sched->curRDPTask = 0;
    task->state &= ~OS_SC_NEEDS_RDP;

    __scTaskComplete(sched, task);

    state = ((sched->curRSPTask == 0) << 1) | (sched->curRDPTask == 0);
    if (__scSchedule(sched, &sp, &dp, state) != state) {
        __scExec(sched, sp, dp);
    }
}
