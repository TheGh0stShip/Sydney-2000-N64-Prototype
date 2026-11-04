#ifndef LEAF_NAME
#define LEAF_NAME updateTimedAnimationRecords
#endif
#ifndef TIME_NAME
#define TIME_NAME getTime
#endif
#ifndef COPY_NAME
#define COPY_NAME copyBytes
#endif

typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 mode;
    u8 frameCount;
    s8 frame;
    s8 step;
    u32 padding04;
    u32 alternateSeconds;
    u32 alternateFraction;
    void *destination;
    u8 *frames;
    u32 frameSize;
    u32 seconds;
    u32 fraction;
    u32 useGlobalInterval;
    u8 padding2C[4];
} TimedAnimationRecord;

extern u32 animationUpdateBlocked __asm__("D_80047818");
extern u32 animationRecordCount __asm__("D_8004798C");
extern u32 globalIntervalSeconds __asm__("D_80047990");
extern u32 globalIntervalFraction __asm__("D_80047994");
extern TimedAnimationRecord *animationRecords __asm__("D_8005A0A8");

extern u32 TIME_NAME(void);
extern void COPY_NAME(void *destination, const void *source, u32 size);

void LEAF_NAME(void)
{
    u32 nowLow;
    u32 nowHigh;
    u32 i;

    if (animationUpdateBlocked != 0) {
        return;
    }
    nowLow = TIME_NAME();
    nowHigh = 0;
    for (i = 0; i < animationRecordCount; i++) {
        TimedAnimationRecord *record = &animationRecords[i];
        u32 intervalSeconds;
        u32 intervalFraction;
        if (record->useGlobalInterval != 0) {
            intervalSeconds = globalIntervalSeconds;
            intervalFraction = globalIntervalFraction;
        } else {
            intervalSeconds = record->alternateSeconds;
            intervalFraction = record->alternateFraction;
        }
        if (nowHigh < record->fraction ||
            (nowHigh == record->fraction && nowLow <= record->seconds)) {
            continue;
        }
        if (record->mode == 1) {
            record->frame++;
            if (record->frame == record->frameCount) {
                record->frame = 0;
            }
        } else if (record->mode == 2) {
            record->frame += record->step;
            if (record->frame == record->frameCount) {
                record->frame -= 2;
                record->step = -1;
            }
            if (record->frame == -1) {
                record->frame = 1;
                record->step = 1;
            }
        } else if (record->mode == 3) {
            s32 count = (s32)(nowHigh & 15) - 1;
            while (count != -1) {
                record->frame++;
                if (record->frame == record->frameCount) {
                    record->frame = 0;
                }
                count--;
            }
        }
        COPY_NAME(record->destination,
                  record->frames + record->frameSize * record->frame,
                  record->frameSize);
        record->seconds = nowLow;
        record->fraction = nowHigh;
        (void)intervalSeconds;
        (void)intervalFraction;
    }
}
