#ifndef LEAF_NAME
#define LEAF_NAME selectAudioRuntimeRecord
#endif
#ifndef EXISTS_NAME
#define EXISTS_NAME recordIdExists
#endif
#ifndef START_NAME
#define START_NAME startStreamChannel
#endif

typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 state;
    u32 field04;
    u16 field08;
    u16 audioId;
    u32 field0C;
    s32 time;
    u32 field14;
    s32 tieValue;
    u32 field1C;
    s32 priority;
} AudioRuntimeRecord;

extern u32 selectionLocked __asm__("D_800651D0");
extern s32 selectionTime __asm__("D_800651E4");
extern u16 currentAudioId __asm__("D_80065002");
extern AudioRuntimeRecord audioRuntimeRecords[10] __asm__("D_80065054");
extern AudioRuntimeRecord *selectedAudioRecord __asm__("D_800651BC");
extern s32 selectedPriority __asm__("D_800651C0");
extern u32 audioBusy __asm__("D_80065004");
extern u16 selectedStream __asm__("D_80065000");
extern void *audioIdTable[] __asm__("D_8006B800");
extern u32 audioConfiguration[] __asm__("D_800F1AE0");

extern s32 EXISTS_NAME(u16 id);
extern u32 START_NAME(void *resource, u32 volume, u16 configuration);

s32 LEAF_NAME(void *unused, s32 time)
{
    s32 candidates[10];
    s32 count;

    s32 i;

    AudioRuntimeRecord *record;

    (void)unused;
    selectionTime = time;
    if (selectionLocked != 0 || EXISTS_NAME(currentAudioId) != 0) {
        return 1;
    }

    if (selectedAudioRecord != 0) {
        selectedAudioRecord->state = 0;
        selectedAudioRecord = 0;
        selectedPriority = 0;
    }

    count = 0;
    for (i = 0; i < 10; i++) {
        record = &audioRuntimeRecords[i];
        if (record->state == 2 && time >= record->time) {
            candidates[count++] = i;
        }
    }

    if (count > 0) {
        selectedAudioRecord = &audioRuntimeRecords[candidates[0]];
        selectedPriority = selectedAudioRecord->priority;
        for (i = 1; i < count; i++) {
            record = &audioRuntimeRecords[candidates[i]];
            if (selectedPriority < record->priority ||
                (selectedPriority == record->priority &&
                 (record->time < selectedAudioRecord->time ||
                  (record->time == selectedAudioRecord->time &&
                   record->tieValue < selectedAudioRecord->tieValue)))) {
                selectedAudioRecord = record;
                selectedPriority = record->priority;
            }
        }
    }

    if (selectedAudioRecord != 0) {
        u16 id = selectedAudioRecord->audioId;
        u16 configuration = (u16)audioConfiguration[28];
        if (audioBusy == 0) {
            selectedStream = (u16)START_NAME(audioIdTable[id], 64, configuration);
        }
    }
    return 1;
}
