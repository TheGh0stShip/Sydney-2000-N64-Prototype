#include <sched.h>

void __scAppendList(OSSched* sched, OSScTask* task) {
    long type = task->list.t.type;

    if (type == M_AUDTASK) {
        if (sched->audioListTail != 0) {
            sched->audioListTail->next = task;
        } else {
            sched->audioListHead = task;
        }

        sched->audioListTail = task;
        sched->doAudio = 1;
    } else {
        if (sched->gfxListTail != 0) {
            sched->gfxListTail->next = task;
        } else {
            sched->gfxListHead = task;
        }

        sched->gfxListTail = task;
    }

    task->next = 0;
    task->state = task->flags & OS_SC_RCP_MASK;
}
