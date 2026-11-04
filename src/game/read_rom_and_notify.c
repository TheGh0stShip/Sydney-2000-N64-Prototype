#include <ultra64.h>

#ifndef LEAF_NAME
#define LEAF_NAME readRomAndNotify
#endif

void LEAF_NAME(u32 deviceAddress, void *destination, u32 size,
               OSMesgQueue *notifyQueue) {
    OSMesgQueue completionQueue;
    OSMesg completionMessage;
    OSIoMesg ioMessage;

    osCreateMesgQueue(&completionQueue, &completionMessage, 1);
    osInvalDCache(destination, size);
    osPiStartDma(&ioMessage, OS_MESG_PRI_NORMAL, OS_READ, deviceAddress,
                 destination, size, &completionQueue);
    osRecvMesg(&completionQueue, 0, OS_MESG_BLOCK);
    osSendMesg(notifyQueue, 0, OS_MESG_BLOCK);
}
