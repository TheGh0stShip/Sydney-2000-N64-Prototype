#ifndef LEAF_NAME
#define LEAF_NAME updateAudioPlayback
#endif
#ifndef FINISH_MUSIC_NAME
#define FINISH_MUSIC_NAME finishMusicResource
#endif
#ifndef VOLUME_NAME
#define VOLUME_NAME setChannelVolume
#endif
#ifndef POLL_NAME
#define POLL_NAME pollChannel
#endif
#ifndef STOP_NAME
#define STOP_NAME stopChannel
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseResource
#endif
#ifndef SHUTDOWN_NAME
#define SHUTDOWN_NAME shutdownMusicConfiguration
#endif
#ifndef PLAY_NAME
#define PLAY_NAME playSound
#endif
#ifndef SET_VOLUME_NAME
#define SET_VOLUME_NAME setSoundVolume
#endif
#ifndef STOP_SOUND_NAME
#define STOP_SOUND_NAME stopSound
#endif
#ifndef IS_PLAYING_NAME
#define IS_PLAYING_NAME isSoundPlaying
#endif
#ifndef FILL_NAME
#define FILL_NAME fillBytes
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;

typedef struct SoundRecord {
    s32 active;
    s32 enabled;
    s32 special;
    s32 pending;
    s32 sound;
    s32 pan;
    s32 volume;
    s32 unused1C[6];
    s32 handle;
    u8 stopWhenFaded;
    u8 unused39;
    s16 fadeSteps;
    s32 fadeStep;
} SoundRecord;

extern SoundRecord soundRecords[20] __asm__("D_8006B2B0");
extern volatile s32 audioConfiguration[] __asm__("D_800F1AE0");
extern u8 memoryContext[] __asm__("D_800F2758");
extern volatile u32 resourceLookupBusy __asm__("D_80043714");
extern volatile u32 audioClock __asm__("D_80064F5C");
extern volatile s32 transitionFirstActive __asm__("D_80064F60");
extern volatile s32 audioRecordLock __asm__("D_80064F64");
extern volatile s32 transitionFirstMode __asm__("D_80064F6C");
extern volatile s32 transitionSecondMode __asm__("D_80064F70");
extern volatile s32 transitionTarget __asm__("D_80064F74");
extern volatile s32 transitionCurrent __asm__("D_80064F78");
extern volatile s32 transitionEnabled __asm__("D_80064F7C");
extern volatile s32 transitionLimit __asm__("D_80064F80");
extern volatile u32 activeSoundCount __asm__("D_80064F88");
extern volatile u32 peakSoundCount __asm__("D_80064F8C");
extern volatile u32 delayedSound __asm__("D_80064F90");
extern volatile s32 musicFinishing __asm__("D_80064F98");
extern void *volatile musicResource __asm__("D_80064F9C");

extern void FINISH_MUSIC_NAME(void *resource);
extern void VOLUME_NAME(int channel, int value);
extern int POLL_NAME(int channel);
extern void STOP_NAME(int channel, int value);
extern void RELEASE_NAME(void *context, void **resource);
extern void SHUTDOWN_NAME(void *configuration);
extern s32 PLAY_NAME(u32 sound, int volume, int pan, int pitch, int priority);
extern void SET_VOLUME_NAME(s32 handle, int volume);
extern void STOP_SOUND_NAME(s32 handle, int value);
extern int IS_PLAYING_NAME(s32 handle);
extern void FILL_NAME(void *destination, u32 value, u32 size);

void LEAF_NAME(void)
{
    SoundRecord *record;
    int index;

    activeSoundCount = 0;
    if (audioRecordLock == 0) {
        if (musicFinishing != 0) {
            FINISH_MUSIC_NAME(musicResource);
        }
        musicFinishing = 0;

        if (transitionEnabled == 1) {
            if (transitionLimit != audioConfiguration[27] && transitionFirstActive == 0) {
                transitionLimit = audioConfiguration[27];
                VOLUME_NAME(2, audioConfiguration[27]);
            }
            if (POLL_NAME(2) == 0) {
                STOP_NAME(2, 0);
                if (musicResource != 0) {
                    RELEASE_NAME(memoryContext, (void **)&musicResource);
                }
                transitionEnabled = 0;
            }
            if (transitionFirstMode != 0) {
                VOLUME_NAME(2, transitionTarget);
                transitionTarget += 200;
                if (transitionTarget >= transitionCurrent) {
                    transitionFirstMode = 0;
                    transitionFirstActive = 0;
                }
            }
            if (transitionSecondMode != 0) {
                VOLUME_NAME(2, transitionTarget);
                transitionTarget -= 200;
                if (transitionCurrent >= transitionTarget) {
                    if (transitionCurrent <= 0) {
                        SHUTDOWN_NAME((void *)audioConfiguration);
                        STOP_NAME(2, 0);
                        if (musicResource != 0) {
                            RELEASE_NAME(memoryContext, (void **)&musicResource);
                        }
                    }
                    transitionSecondMode = 0;
                    transitionFirstActive = 0;
                }
            }
        }

        if (delayedSound != 0) {
            if (audioClock >= delayedSound) {
                PLAY_NAME(delayedSound, audioConfiguration[26] / 128, 0x50, 0, -1);
            }
            delayedSound = 0;
        }

        record = soundRecords;
        for (index = 0; index < 20; index++, record++) {
            if (record->enabled == 0) {
                continue;
            }
            if (record->pending != 0 && resourceLookupBusy == 0) {
                record->pending = 0;
                record->handle = PLAY_NAME(record->sound, record->volume / 128, record->pan, 0, -1);
            }
            if (audioRecordLock == 0 && record->fadeSteps != 0) {
                record->fadeSteps--;
                record->volume += record->fadeStep;
                SET_VOLUME_NAME(record->handle, record->volume / 128);
                if (record->fadeSteps <= 0 && record->stopWhenFaded != 0) {
                    STOP_SOUND_NAME(record->handle, 0);
                    FILL_NAME(record, 0, 0x40);
                }
            }
            if (IS_PLAYING_NAME(record->handle) != 0) {
                activeSoundCount++;
            } else {
                FILL_NAME(record, 0, 0x40);
            }
        }
    } else {
        if (delayedSound != 0) {
            if (audioClock >= delayedSound) {
                PLAY_NAME(delayedSound, audioConfiguration[26] / 128, 0x50, 0, -1);
            }
            delayedSound = 0;
        }
    }

    if (peakSoundCount < activeSoundCount) {
        peakSoundCount = activeSoundCount;
    }
}
