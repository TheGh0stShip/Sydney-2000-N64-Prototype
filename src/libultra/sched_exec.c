#include <sched.h>

#define OS_SC_YIELD 0x0010
#define OS_SC_YIELDED 0x0020

static int dp_busy = 0;
static int dpCount = 0;

void __scExec(OSSched* sched, OSScTask* sp, OSScTask* dp) {
    if (sp != 0) {
        if (sp->list.t.type == M_AUDTASK) {
            osWritebackDCacheAll();
        }

        sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);
        osSpTaskLoad(&sp->list);
        osSpTaskStartGo(&sp->list);
        sched->curRSPTask = sp;
        if (sp == dp) {
            sched->curRDPTask = dp;
        }
    }

    if ((dp != 0) && (dp != sp)) {
        osDpSetNextBuffer(dp->list.t.output_buff,
                          *dp->list.t.output_buff_size);

        dp_busy = 1;
        dpCount = 0;
        sched->curRDPTask = dp;
    }
}
