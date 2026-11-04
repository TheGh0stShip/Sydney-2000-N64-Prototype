#ifndef LEAF_NAME
#define LEAF_NAME initializeStreamChannels
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateStreamMemory
#endif

#ifndef DEFAULT_CALLBACK_NAME
#define DEFAULT_CALLBACK_NAME defaultStreamCallback
#endif

typedef struct StreamChannel {
    unsigned char pad0000[0x11E0];
    void *firstBuffer;
    void *secondBuffer;
    unsigned short identifier;
    unsigned char pad11EA[0x16];
} StreamChannel;

extern StreamChannel *streamChannels;
extern unsigned short streamChannelCount;
extern unsigned short streamChannelIndex;
extern int streamChannelArgument;
extern void *streamChannelCallback;
extern void *ALLOCATE_NAME(int size);
extern void DEFAULT_CALLBACK_NAME(void);

int LEAF_NAME(int count, int argument, int unused, void *callback)
{
    int index;

    (void)unused;
    streamChannelCount = 0;
    streamChannelIndex = 0;
    streamChannelArgument = argument;
    streamChannels = ALLOCATE_NAME(count * 0x1200);
    if (streamChannels == 0) {
        return 0;
    }
    for (index = 0; index < count; index++) {
        streamChannels[index].identifier = 0xFFFF;
        streamChannels[index].firstBuffer = ALLOCATE_NAME(0x1400);
        if (streamChannels[index].firstBuffer == 0) {
            return 0;
        }
        streamChannels[index].secondBuffer = ALLOCATE_NAME(0x20);
        if (streamChannels[index].secondBuffer == 0) {
            return 0;
        }
    }
    streamChannelCount = count;
    streamChannelCallback = callback;
    if (callback == 0) {
        streamChannelCallback = DEFAULT_CALLBACK_NAME;
    }
    return 1;
}
