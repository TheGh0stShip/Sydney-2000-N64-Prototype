#ifndef LEAF_NAME
#define LEAF_NAME startStreamChannel
#endif

#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeStreamState
#endif

#ifndef SET_PAN_NAME
#define SET_PAN_NAME setStreamPan
#endif

typedef struct StreamChannel {
    unsigned char pad0000[0x11A0];
    unsigned short position;
    unsigned short rate;
    int value11A4;
    unsigned char pad11A8[0x34];
    unsigned char value11DC;
    unsigned char status;
    unsigned char mode;
    unsigned char pad11DF;
    void *firstBuffer;
    void *secondBuffer;
    unsigned short identifier;
    unsigned char playing;
    unsigned char pad11EB;
    int value11EC;
    float time;
    int value11F4;
    unsigned short left;
    unsigned short right;
    unsigned char pad11FC[4];
} StreamChannel;

extern StreamChannel *streamChannels;
extern unsigned short streamChannelCount;
extern unsigned short streamChannelIndex;
extern void *streamChannelCallback;

extern void INITIALIZE_NAME(StreamChannel *channel, int argument, void *buffer,
                            int size, void *callback);
extern void SET_PAN_NAME(unsigned short handle, signed char pan,
                         unsigned short volume);

unsigned short LEAF_NAME(int argument, signed char pan, unsigned short volume)
{
    int index;

    for (index = 0; index < streamChannelCount; index++) {
        if (streamChannels[index].identifier == 0xFFFF) {
            streamChannels[index].identifier = streamChannelIndex++ & 0xFFF;
            INITIALIZE_NAME(&streamChannels[index], argument,
                            streamChannels[index].firstBuffer, 0xA00,
                            streamChannelCallback);
            SET_PAN_NAME(streamChannels[index].identifier, pan, volume);
            streamChannels[index].mode = 4;
            return streamChannels[index].identifier;
        }
    }
    return 0xFFFF;
}
