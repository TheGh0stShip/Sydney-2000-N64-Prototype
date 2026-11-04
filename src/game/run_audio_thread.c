#ifndef LEAF_NAME
#define LEAF_NAME runAudioThread
#endif
#ifndef GET_STATUS_NAME
#define GET_STATUS_NAME getAudioStatus
#endif
#ifndef GET_LENGTH_NAME
#define GET_LENGTH_NAME getAudioLength
#endif
#ifndef FLUSH_NAME
#define FLUSH_NAME flushDmaFreeList
#endif
#ifndef SET_BUFFER_NAME
#define SET_BUFFER_NAME setAudioBuffer
#endif
#ifndef SELECT_NAME
#define SELECT_NAME selectRuntimeBuffer
#endif
#ifndef PHYSICAL_NAME
#define PHYSICAL_NAME virtualToPhysical
#endif
#ifndef SYNTHESIZE_NAME
#define SYNTHESIZE_NAME synthesizeAudio
#endif
#ifndef SERVICE_NAME
#define SERVICE_NAME serviceStreamChannels
#endif
#ifndef MIX_NAME
#define MIX_NAME mixStreamChannels
#endif

typedef struct {
    long long align;
} AudioCommand;
typedef struct {
    short *pointer;
    int length;
} AudioBuffer;
typedef struct {
    AudioCommand *list;
    int size;
    void *callback;
    void *data;
} AudioTask;
typedef struct {
    void (*start)(void);
    void (*wait)(void);
    void (*submit)(AudioTask *task);
} AudioScheduler;

extern AudioCommand *commandList;
extern AudioBuffer *audioBuffers;
extern AudioScheduler *audioScheduler;
extern AudioBuffer *previousBuffer;
extern char audioThreadData[];
extern void audioTaskCallback(void);
extern int GET_STATUS_NAME(void);
extern unsigned int GET_LENGTH_NAME(void);
extern void FLUSH_NAME(void);
extern void SET_BUFFER_NAME(short *buffer, int size);
extern int SELECT_NAME(unsigned int samples);
extern void *PHYSICAL_NAME(void *address);
extern AudioCommand *SYNTHESIZE_NAME(AudioCommand *commands, int *commandLength,
                                     void *output, int outputLength);
extern void SERVICE_NAME(void);
extern AudioCommand *MIX_NAME(AudioCommand *commands, int *commandLength,
                              void *output, int outputLength);

void LEAF_NAME(void)
{
    AudioTask task;
    int commandLength;
    unsigned int frame;
    int status;
    unsigned int samples;
    AudioBuffer *buffer;
    AudioCommand *commands;

    task.list = commandList;
    task.callback = audioTaskCallback;
    task.data = audioThreadData;
    frame = 0;
    audioScheduler->start();
    while (1) {
        audioScheduler->wait();
        status = GET_STATUS_NAME();
        samples = GET_LENGTH_NAME() >> 2;
        if (status < 0)
            continue;
        FLUSH_NAME();
        if (previousBuffer && commandLength)
            SET_BUFFER_NAME(previousBuffer->pointer, previousBuffer->length << 2);
        buffer = &audioBuffers[frame];
        buffer->length = SELECT_NAME(samples);
        commands = SYNTHESIZE_NAME(commandList, &commandLength,
                                   PHYSICAL_NAME(buffer->pointer),
                                   buffer->length);
        SERVICE_NAME();
        commands = MIX_NAME(commands, &commandLength,
                            PHYSICAL_NAME(buffer->pointer), buffer->length);
        if (commandLength) {
            task.size = (commands - commandList) * sizeof(AudioCommand);
            audioScheduler->submit(&task);
            previousBuffer = buffer;
        }
        frame = (frame + 1) % 3;
    }
}
