#ifndef LEAF_NAME
#define LEAF_NAME serviceStreamChannels
#endif

#ifndef UPDATE_NAME
#define UPDATE_NAME updateStreamChannel
#endif

#ifndef TRANSITION_NAME
#define TRANSITION_NAME transitionStreamChannel
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
extern int streamChannelArgument;

extern void UPDATE_NAME(StreamChannel *channel);
extern void TRANSITION_NAME(StreamChannel *channel);

void LEAF_NAME(void)
{
    int index;
    StreamChannel *channel;

    for (index = 0; index < streamChannelCount; index++) {
        if (streamChannels[index].identifier == 0xFFFF) {
            continue;
        }
        UPDATE_NAME(&streamChannels[index]);
        switch (streamChannels[index].status) {
        case 2:
            channel = &streamChannels[index];
            channel->playing = 1;
            channel->value11EC = 0;
            streamChannels[index].time =
                (float)((streamChannels[index].rate << 15) /
                        streamChannelArgument) /
                32768.0f;
            streamChannels[index].value11F4 = 0;
            TRANSITION_NAME(&streamChannels[index]);
            break;
        case 4:
            streamChannels[index].identifier = 0xFFFF;
            break;
        }
    }
}
