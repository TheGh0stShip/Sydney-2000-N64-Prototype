#ifndef LEAF_NAME
#define LEAF_NAME setStreamPan
#endif

typedef struct StreamChannel {
    unsigned char pad0000[0x11E8];
    unsigned short identifier;
    unsigned char pad11EA[0xE];
    unsigned short left;
    unsigned short right;
    unsigned char pad11FC[4];
} StreamChannel;

extern StreamChannel *streamChannels;
extern unsigned short streamChannelCount;

void LEAF_NAME(unsigned short handle, signed char pan, unsigned short volume)
{
    int index;

    if (handle == 0xFFFF)
        return;
    for (index = 0; index < streamChannelCount; index++) {
        if (streamChannels[index].identifier != handle)
            continue;
        if (pan >= 0 && pan < 64) {
            streamChannels[index].left =
                volume * ((pan * 0.25f) / 64.0f + 0.75f);
            streamChannels[index].right = volume * ((pan * 0.75f) / 64.0f);
        } else if (pan > 64) {
            streamChannels[index].left =
                volume * (((0x7F - pan) * 0.75f) / 63.0f);
            streamChannels[index].right =
                volume * (((pan - 0x40) * 0.25f) / 63.0f + 0.75f);
        } else {
            streamChannels[index].left = volume * 0.75f;
            streamChannels[index].right = volume * 0.75f;
        }
    }
}
