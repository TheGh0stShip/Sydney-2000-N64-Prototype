#ifndef LEAF_NAME
#define LEAF_NAME releaseSlotEntries
#endif

#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

#ifndef STATE_NAME
#define STATE_NAME slotEntryState
#endif

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 flags;
    u8 padding[28];
} SlotEntry;

typedef struct {
    u32 firstActiveSlot;
    u32 activeSlotCount;
    u8 padding08[0x40];
    u32 entryCounts[8];
    u8 padding68[0x20];
    SlotEntry *entries[8];
    void *context;
} SlotEntryState;

extern SlotEntryState STATE_NAME;
extern void RELEASE_NAME(void *context, void **handle);

s32 LEAF_NAME(u8 *slot)
{
    u32 entry;
    u32 index;

    index = *slot;
    if ((index & 0x40) == 0) {
        return -992;
    }

    *slot = index & ~0x40;
    STATE_NAME.activeSlotCount--;
    for (entry = 0; entry < STATE_NAME.entryCounts[index]; entry++) {
        STATE_NAME.entries[index][entry].flags &= ~1U;
    }

    STATE_NAME.entryCounts[index] = 0;
    if (STATE_NAME.entries[index] != 0) {
        RELEASE_NAME(STATE_NAME.context, (void **)&STATE_NAME.entries[index]);
    }
    index = *slot;
    if (index < STATE_NAME.firstActiveSlot) {
        STATE_NAME.firstActiveSlot = index;
    }
    return 0;
}
