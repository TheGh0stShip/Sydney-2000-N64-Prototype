typedef unsigned int u32;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;

#ifndef LEAF_NAME
#define LEAF_NAME update_gsm_stream_channel
#endif
#ifndef RECEIVE_NAME
#define RECEIVE_NAME receive_message
#endif
#ifndef DECODE_NAME
#define DECODE_NAME decode_gsm_stream_frame
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clear_bytes
#endif

typedef struct GsmStreamChannel {
    unsigned char pad0000[0x190];
    void (*dma)(u32, void *, int, void *);
    u32 rom;
    long long *ring;
    u32 ring_size;
    u32 data[0x400];
    u16 frames;
    u16 rate;
    u32 words;
    u32 remaining;
    unsigned char queue[0x1C];
    u32 bit_position;
    u32 consumed;
    u32 fetched;
    u32 read;
    u32 write;
    s8 pending;
    s8 state;
    s8 max_frames;
} GsmStreamChannel;

extern int RECEIVE_NAME(void *, void *, int);
extern void DECODE_NAME(GsmStreamChannel *, s16 *);
extern void CLEAR_NAME(void *, int);

void LEAF_NAME(GsmStreamChannel *stream) {
    int n;
    int length;
    u32 used;
    u32 size;
    u32 write;

    n = stream->max_frames;
    if (stream->pending) {
        if (RECEIVE_NAME(stream->queue, 0, 0) >= 0) {
            if (stream->fetched == 0) {
                stream->frames = (stream->data[1] >> 16) & 0xFFFF;
                stream->rate = stream->data[1] & 0xFFFF;
                stream->words = stream->data[2] & 0xFFFFFF;
                stream->bit_position = 0x60;
            }
            stream->fetched += 0x400;
            if (stream->words > 0x100) {
                stream->words -= 0x100;
            } else {
                stream->words = 0;
            }
            stream->pending = 0;
        }
    }
    if (!stream->pending) {
        if (stream->state == 1 || stream->state == 2 || stream->state == 3) {
            if (stream->fetched - stream->consumed <= 0xC00) {
                if (stream->fetched == 0) {
                    length = 0x400;
                } else if (stream->words > 0x100) {
                    length = 0x400;
                } else {
                    length = stream->words * 4;
                }
                if (length > 0) {
                    stream->pending = 1;
                    stream->dma(
                        stream->rom + stream->fetched,
                        &((long long *)stream->data)[
                            (stream->fetched & 0xFFF) >> 3],
                        length,
                        stream->queue
                    );
                }
            }
        }
    }
    write = stream->write;
    used = write - stream->read;
    size = stream->ring_size;
    while (used < size - 0xA0 &&
           (stream->state == 1 || stream->frames > 0) &&
           ((stream->fetched != 0 && stream->words == 0) ||
            stream->fetched - stream->consumed > 0x24) &&
           n > 0) {
        DECODE_NAME(stream, &stream->ring[(write % size) >> 2]);
        stream->consumed = (stream->bit_position >> 3) & ~3;
        stream->write += 0xA0;
        if (--stream->frames == 0) {
            stream->remaining = stream->ring_size;
        }
        n--;
        write = stream->write;
        used = write - stream->read;
        size = stream->ring_size;
    }
    if (stream->state == 3 || stream->state == 4) {
        if (stream->frames <= 0) {
            while (used < size - 0xA0 && n > 0) {
                CLEAR_NAME(&stream->ring[(write % size) >> 2], 0x140);
                stream->write += 0xA0;
                write = stream->write;
                used = write - stream->read;
                size = stream->ring_size;
                n--;
            }
        }
    }
    if (stream->state == 1 && used >= size - 0x140) {
        stream->state = 2;
    }
}
