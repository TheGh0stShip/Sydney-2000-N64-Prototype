#ifndef LEAF_NAME
#define LEAF_NAME dmaNewBuffer
#endif
#ifndef START_DMA_NAME
#define START_DMA_NAME startDma
#endif

typedef struct DmaBuffer {
    struct DmaBuffer *previous;
    struct DmaBuffer *next;
    int lastFrame;
    unsigned int startAddress;
    unsigned char *pointer;
} DmaBuffer;

typedef struct IoMessage {
    unsigned short type;
    unsigned char priority;
    unsigned char status;
    void *returnQueue;
    void *dramAddress;
    unsigned int deviceAddress;
    unsigned int size;
    void *piHandle;
} IoMessage;

extern int dmaStatus;
extern DmaBuffer *dmaActiveList;
extern DmaBuffer *dmaFreeList;
extern IoMessage *dmaMessages;
extern unsigned int dmaBufferSize;
extern int dmaMessageIndex;
extern char dmaQueue[];
extern void *cartHandle;
extern void *diskHandle;
extern int START_DMA_NAME(void *handle, IoMessage *message, int direction);

DmaBuffer *LEAF_NAME(unsigned int address, int length)
{
    void *handle;
    unsigned int end;
    DmaBuffer *cursor;
    DmaBuffer *last;
    DmaBuffer *buffer;
    DmaBuffer *next;
    IoMessage *message;
    int index;

    if ((address & 0xFF000000) == 0xFF000000) {
        handle = diskHandle;
        address = address & 0xFFFFFF;
        address = address + 0x140000;
    } else {
        if (dmaStatus & 1)
            return 0;
        handle = cartHandle;
    }
    last = 0;
    end = address + length;
    for (cursor = dmaActiveList; cursor != 0; cursor = cursor->next) {
        if (address < cursor->startAddress)
            break;
        if (end <= cursor->startAddress + dmaBufferSize)
            return cursor;
        last = cursor;
    }
    buffer = dmaFreeList;
    if (buffer == 0)
        return dmaActiveList;
    dmaFreeList = buffer->next;
    if (last) {
        next = last->next;
        buffer->next = next;
        if (next)
            next->previous = buffer;
        buffer->previous = last;
        last->next = buffer;
    } else {
        buffer->previous = 0;
        buffer->next = dmaActiveList;
        if (dmaActiveList)
            dmaActiveList->previous = buffer;
        dmaActiveList = buffer;
    }
    index = dmaMessageIndex;
    buffer->startAddress = address & ~1;
    buffer->lastFrame = 2;
    dmaMessageIndex = index + 1;
    message = &dmaMessages[index];
    message->priority = 0;
    message->returnQueue = dmaQueue;
    message->dramAddress = buffer->pointer;
    message->deviceAddress = buffer->startAddress;
    message->size = dmaBufferSize;
    START_DMA_NAME(handle, message, 0);
    return buffer;
}
