#ifndef LEAF_NAME
#define LEAF_NAME releaseActiveSlots
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef STATE_NAME
#define STATE_NAME activeSlotState
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 flags;
    u8 padding[28];
} SlotEntry;

typedef struct {
    u32 active;
    u32 count;
    u8 padding08[0x40];
    u32 entryCounts[8];
    u8 padding68[0x20];
    SlotEntry *entries[8];
    void *context;
} ActiveSlotState;

extern ActiveSlotState STATE_NAME;
extern void RELEASE_NAME(void *context, void **handle);

u32 LEAF_NAME(void) {
    u32 slot;
    u32 entry;
    SlotEntry *entries;

    for (slot = 0; slot < 8 && STATE_NAME.count != 0; slot++) {
        entries = STATE_NAME.entries[slot];
        if (entries != 0) {
            for (entry = 0; entry < STATE_NAME.entryCounts[slot]; entry++) {
                if (entries[entry].flags & 1) {
                    entries[entry].flags &= ~1U;
                }
            }
            STATE_NAME.count--;
            STATE_NAME.entryCounts[slot] = 0;
            RELEASE_NAME(STATE_NAME.context, (void **)&STATE_NAME.entries[slot]);
        }
    }
    STATE_NAME.active = 0;
    return 0;
}
