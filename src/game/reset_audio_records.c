#ifndef LEAF_NAME
#define LEAF_NAME resetAudioRecords
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME audioRecords
#endif

#ifndef FIRST_STATE_NAME
#define FIRST_STATE_NAME firstAudioState
#endif

#ifndef SECOND_STATE_NAME
#define SECOND_STATE_NAME secondAudioState
#endif

#ifndef FIRST_RELEASE_NAME
#define FIRST_RELEASE_NAME releaseFirstAudioHandle
#endif

#ifndef SECOND_RELEASE_NAME
#define SECOND_RELEASE_NAME releaseSecondAudioHandle
#endif

#ifndef FILL_NAME
#define FILL_NAME fillBytes
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 RECORDS_NAME[20][16];
extern u32 FIRST_STATE_NAME;
extern u32 SECOND_STATE_NAME;
extern void FIRST_RELEASE_NAME(u32 handle, u32 argument);
extern void SECOND_RELEASE_NAME(u32 handle, u32 argument);
extern void FILL_NAME(void *destination, u32 value, u32 size);

void LEAF_NAME(void) {
    volatile u32 *record;
    int index;

    FIRST_STATE_NAME = 0;
    SECOND_STATE_NAME = 0;
    record = RECORDS_NAME[0];
    for (index = 0; index < 20; index++, record += 16) {
        FIRST_RELEASE_NAME(record[13], 0);
        SECOND_RELEASE_NAME(record[13], 0);
        FILL_NAME((void *)record, 0, 0x40);
    }
}
