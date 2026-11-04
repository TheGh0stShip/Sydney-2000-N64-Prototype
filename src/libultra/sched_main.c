#include <sched.h>

#define VIDEO_MSG 666
#define RSP_DONE_MSG 667
#define RDP_DONE_MSG 668
#define PRE_NMI_MSG 669

extern void __scHandleRetrace(OSSched* sched);
extern void __scHandleRSP(OSSched* sched);
extern void __scHandleRDP(OSSched* sched);

void __scMain(void* arg) {
    OSMesg msg;
    OSSched* sched = (OSSched*)arg;
    OSScClient* client;

    while (1) {
        osRecvMesg(&sched->interruptQ, (OSMesg*)&msg, OS_MESG_BLOCK);

        switch ((int)msg) {
            case VIDEO_MSG:
                __scHandleRetrace(sched);
                break;

            case RSP_DONE_MSG:
                __scHandleRSP(sched);
                break;

            case RDP_DONE_MSG:
                __scHandleRDP(sched);
                break;

            case PRE_NMI_MSG:
                for (client = sched->clientList; client != 0;
                     client = client->next) {
                    osSendMesg(client->msgQ, (OSMesg)&sched->prenmiMsg,
                               OS_MESG_NOBLOCK);
                }
                break;
        }
    }
}
