#ifndef LEAF_NAME
#define LEAF_NAME registerDirectionalLight
#endif
#ifndef FIND_SLOT_NAME
#define FIND_SLOT_NAME findFreeLightSlot
#endif
#ifndef TRANSFORM_NAME
#define TRANSFORM_NAME transformLightVector
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateMemory
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    u8 flags;
    u8 red;
    u8 green;
    u8 blue;
    s32 mode;
    u8 padding08[0xC];
    u8 transform[0x14];
    u32 channelMask;
} LightRequest;

typedef struct {
    u32 flags;
    u8 padding04[4];
    u8 col[3];
    u8 pad1;
    u8 colc[3];
    u8 pad2;
    s8 dir[3];
    u8 pad3;
    u8 padding14[4];
    u32 channelMask;
    u8 padding1C[4];
} LightEntry;

typedef struct {
    u32 index;
    u32 count;
    u32 ambientColors[16];
    u32 entryCounts[8];
    u32 entryMasks[8];
    LightEntry *entries[8];
} LightState;

extern LightState lightState __asm__("D_80043D48");
extern void *lightAllocator __asm__("D_80043DF0");
extern u32 lightRevision __asm__("D_80043D20");
extern char lightMemoryName[] __asm__("D_80000540");
extern double lightDirectionScale __asm__("D_80000550");

extern u32 FIND_SLOT_NAME(void);
extern void TRANSFORM_NAME(void *source, float output[3]);
extern void ALLOCATE_NAME(void *allocator, void **output, u32 size,
                          const char *name);

s32 LEAF_NAME(LightRequest *request)
{
    LightState *state;
    u32 index;
    u32 count;
    u32 slot;
    u32 bit;
    u32 found;
    float vector[3];
    u8 reserved[0xF4]; /* unused scratch kept in the frame */

    if (request->flags & 0x40) {
        return -991;
    }

    if (request->mode == 2) {
        /* Ambient request: pack the color into every channel. */
        state = &lightState;
        for (index = 0; index < 3; index++) {
            state->ambientColors[index] =
                request->blue | (request->green << 8) |
                (request->red << 16) | 0xFF000000;
        }
        return 0;
    }
    if (request->mode == 0x10) {
        return 0;
    }

    request->flags = FIND_SLOT_NAME();
    if (request->flags >= 8) {
        return -991;
    }

    TRANSFORM_NAME(request->transform, vector);
    vector[0] = (float)((double)vector[0] * lightDirectionScale);
    vector[1] = (float)((double)vector[1] * lightDirectionScale);
    vector[2] = (float)((double)vector[2] * lightDirectionScale);

    /* One light entry per channel selected in the request mask. */
    index = count = 0;
    slot = request->flags & 0xBF;
    for (; index < 3; index++) {
        if (request->channelMask & (1 << index)) {
            count++;
        }
    }

    state = &lightState;
    state->entryCounts[slot] = count;
    ALLOCATE_NAME(lightAllocator, (void **)&state->entries[slot], count * 32,
                  lightMemoryName);

    bit = 1;
    index = found = 0;
    for (; index < count; index++) {
        while (!found) {
            if (bit & request->channelMask) {
                found = 1;
            } else {
                bit <<= 1;
            }
        }
        state->entries[slot][index].col[0] = request->red;
        state->entries[slot][index].col[1] = request->green;
        state->entries[slot][index].col[2] = request->blue;
        state->entries[slot][index].colc[0] = request->red;
        state->entries[slot][index].colc[1] = request->green;
        state->entries[slot][index].colc[2] = request->blue;
        state->entries[slot][index].dir[0] = (s32)vector[0];
        state->entries[slot][index].dir[1] = (s32)vector[1];
        state->entries[slot][index].dir[2] = (s32)vector[2];
        state->entries[slot][index].channelMask = bit;
        found = 0;
        state->entries[slot][index].flags |= 1;
        bit <<= 1;
    }

    state = &lightState;
    state->entryMasks[slot] = request->channelMask;
    request->flags |= 0x40;
    state->count++;
    lightRevision = state->count;
    return 0;
}
