#include <ultra64.h>

#ifndef LEAF_NAME
#define LEAF_NAME readRom
#endif

extern s32 romQueueInitialized;
extern OSMesgQueue romQueue;
extern OSMesg romMessages[8];

void LEAF_NAME(u32 deviceAddress, void *destination, u32 size) {
    OSIoMesg ioMessage;
    OSMesg completionMessage;
#ifdef CHUNKED
    register s32 remaining __asm__("$17") = size;
    register u32 deviceAddressReg __asm__("$19") = deviceAddress;
    register u8 *destinationReg __asm__("$18") = destination;
    register OSMesgQueue *queue __asm__("$20");
    register s32 chunkSize __asm__("$16");

    __asm__("" : "=r"(remaining), "=r"(deviceAddressReg),
            "=r"(destinationReg)
            : "0"(remaining), "1"(deviceAddressReg),
              "2"(destinationReg));
#else
    register u32 deviceAddressReg __asm__("$19") = deviceAddress;
    register void *destinationReg __asm__("$17") = destination;
    register u32 sizeReg __asm__("$18") = size;
    register OSMesgQueue *queue __asm__("$16");

    __asm__("" : "=r"(deviceAddressReg), "=r"(destinationReg),
            "=r"(sizeReg)
            : "0"(deviceAddressReg), "1"(destinationReg), "2"(sizeReg));
#endif

    if (romQueueInitialized == 0) {
        osCreateMesgQueue(&romQueue, romMessages, 8);
        romQueueInitialized = 1;
    }

#ifdef CHUNKED
    if (remaining != 0) {
        queue = &romQueue;
        do {
            chunkSize = remaining < 2049 ? remaining : 2048;
            osInvalDCache(destinationReg, chunkSize);
#ifdef WRITEBACK_EACH_CHUNK
            osWritebackDCacheAll();
            remaining -= chunkSize;
#endif
            osPiStartDma(&ioMessage, OS_MESG_PRI_HIGH, OS_READ,
                         deviceAddressReg, destinationReg, chunkSize, queue);
            osRecvMesg(queue, &completionMessage, OS_MESG_BLOCK);
            deviceAddressReg += chunkSize;
#ifndef WRITEBACK_EACH_CHUNK
            remaining -= chunkSize;
#endif
            destinationReg += chunkSize;
        } while (remaining != 0);
    }
#else
    osInvalDCache(destinationReg, sizeReg);
    queue = &romQueue;
    __asm__("" : "=r"(queue) : "0"(queue));
    osPiStartDma(&ioMessage, OS_MESG_PRI_HIGH, OS_READ, deviceAddressReg,
                 destinationReg, sizeReg, queue);
    osRecvMesg(queue, &completionMessage, OS_MESG_BLOCK);
#endif
}
