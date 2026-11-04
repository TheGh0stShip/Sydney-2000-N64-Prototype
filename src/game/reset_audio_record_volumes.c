#ifndef LEAF_NAME
#define LEAF_NAME resetAudioRecordVolumes
#endif

#ifndef MASTER_VOLUME_NAME
#define MASTER_VOLUME_NAME setMasterVolume
#endif

#ifndef SET_VOLUME_NAME
#define SET_VOLUME_NAME setRecordVolume
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME audioRecords
#endif

#include "audio_record.h"

typedef signed int s32;
typedef unsigned int u32;

extern AudioRecord RECORDS_NAME[20];
extern s32 audioRecordVolumes[20];
extern u32 audioMasterVolume;
extern u32 audioRecordLock;
extern u32 audioUpdatePending;
extern void MASTER_VOLUME_NAME(s32 type, s32 volume);
extern void SET_VOLUME_NAME(u32 handle, s32 volume);
#ifdef INITIALIZE_VOLUMES
extern u32 audioConfiguration[];
extern u32 audioInitializationObject[];
extern void INITIALIZE_NAME(void *object);
#endif

void LEAF_NAME(void) {
    AudioRecord *record;
    s32 *volume;
    s32 index;

#ifdef INITIALIZE_VOLUMES
    audioRecordLock = 1;
    audioUpdatePending = 1;
    audioMasterVolume = audioConfiguration[27];
    INITIALIZE_NAME(audioInitializationObject);
    MASTER_VOLUME_NAME(2, 0);
#else
    audioRecordLock = 0;
    audioUpdatePending = 0;
    MASTER_VOLUME_NAME(2, audioMasterVolume);
#endif

    record = RECORDS_NAME;
    volume = audioRecordVolumes;
    for (index = 0; index < 20; index++, record++, volume++) {
        if (record->enabled == 0) {
            continue;
        }
#ifdef INITIALIZE_VOLUMES
        *volume = record->volume;
        SET_VOLUME_NAME(record->handle, 0);
#else
        {
        s32 scaledVolume;
        scaledVolume = *volume;
        if (scaledVolume < 0) {
            scaledVolume += 127;
        }
        SET_VOLUME_NAME(record->handle, scaledVolume >> 7);
        }
#endif
    }
}
