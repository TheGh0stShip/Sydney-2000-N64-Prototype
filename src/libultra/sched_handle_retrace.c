#include <sched.h>

extern void __scAppendList(OSSched* sched, OSScTask* task);
extern void __scYield(OSSched* sched);
extern s32 __scSchedule(OSSched* sched, OSScTask** sp, OSScTask** dp,
                        s32 availRCP);
extern void __scExec(OSSched* sched, OSScTask* sp, OSScTask* dp);

void __scHandleRetrace(OSSched* sched) {
    OSScTask* rspTask;
    OSScClient* client;
    s32 state;
    OSScTask* sp = 0;
    OSScTask* dp = 0;

    sched->frameCount++;

    while (osRecvMesg(&sched->cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) !=
           -1) {
        __scAppendList(sched, rspTask);
    }

    if (sched->doAudio && sched->curRSPTask) {
        __scYield(sched);
    } else {
        state = ((sched->curRSPTask == 0) << 1) | (sched->curRDPTask == 0);
        if (__scSchedule(sched, &sp, &dp, state) != state) {
            __scExec(sched, sp, dp);
        }
    }

    for (client = sched->clientList; client != 0; client = client->next) {
        osSendMesg(client->msgQ, (OSMesg)&sched->retraceMsg,
                   OS_MESG_NOBLOCK);
    }
}
