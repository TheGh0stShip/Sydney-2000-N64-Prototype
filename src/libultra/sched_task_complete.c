#include <sched.h>

s32 __scTaskComplete(OSSched* sched, OSScTask* task) {
    static int firsttime = 1;

    if ((task->state & OS_SC_RCP_MASK) == 0) {
        osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);

        if (task->list.t.type == M_GFXTASK) {
            if ((task->flags & OS_SC_SWAPBUFFER) &&
                (task->flags & OS_SC_LAST_TASK)) {
                if (firsttime != 0) {
                    osViBlack(FALSE);
                    firsttime = 0;
                }
                osViSwapBuffer(task->framebuffer);
            }
        }
        return 1;
    }

    return 0;
}
