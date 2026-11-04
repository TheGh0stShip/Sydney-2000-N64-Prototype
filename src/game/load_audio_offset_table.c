#ifndef LEAF_NAME
#define LEAF_NAME loadAudioOffsetTable
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeLookup
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadResource
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef FIND_NAME
#define FIND_NAME findResource
#endif
#ifndef GET_NAME
#define GET_NAME getResource
#endif
#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupLookup
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 word;
} ResourceLookup;

typedef struct {
    u32 unused00[4];
    u32 count;
    u32 unused14;
    u32 dataOffset;
} AudioOffsetHeader;

typedef struct {
    u32 offset;
    u32 unused;
} __attribute__((packed, aligned(1))) AudioOffsetEntry;

extern u8 memoryContext[] __asm__("commandContext");
extern u32 selectedAudioTable __asm__("D_800F271C");
extern char *audioTablePaths[1] __asm__("D_8006502C");
extern char *audioEntryNames[1] __asm__("D_80065008");
extern u32 audioOffsetCount __asm__("D_80065050");
extern u32 *audioOffsets __asm__("D_8006B800");
extern char audioOffsetsTag[] __asm__("D_800015B0");

extern void INITIALIZE_NAME(ResourceLookup *lookup);
extern int LOAD_NAME(char *path, void **result, void *context, u32 mode);
extern void ALLOCATE_NAME(void *context, void **result, u32 size, char *tag);
extern int FIND_NAME(ResourceLookup *lookup, char *name, u32 length);
extern u32 GET_NAME(ResourceLookup *lookup, int index);
extern void CLEANUP_NAME(ResourceLookup *lookup, int *index);
extern u32 RELEASE_NAME(void *context, void **handle);

u32 LEAF_NAME(void)
{
    ResourceLookup lookup;
    void *handle = 0;
    int entryIndex;
    AudioOffsetHeader *header;
    AudioOffsetEntry *entry;
    u32 baseOffset;
    u32 index;

    INITIALIZE_NAME(&lookup);
    if (!LOAD_NAME(audioTablePaths[selectedAudioTable], &handle,
                   memoryContext, 1)) {
        return 0;
    }

    audioOffsets = 0;
    header = (AudioOffsetHeader *)((u8 *)handle + 64);
    audioOffsetCount = header->count;
    ALLOCATE_NAME(memoryContext, (void **)&audioOffsets,
                  header->count * sizeof(u32), audioOffsetsTag);
    entryIndex = FIND_NAME(&lookup, audioEntryNames[selectedAudioTable], 16);
    baseOffset = GET_NAME(&lookup, entryIndex);
    entry = (AudioOffsetEntry *)((u8 *)handle + header->dataOffset);
    for (index = 0; index < header->count; index++) {
        AudioOffsetEntry value = *entry;
        audioOffsets[index] = value.offset + baseOffset;
        entry++;
    }
    CLEANUP_NAME(&lookup, &entryIndex);
    return RELEASE_NAME(memoryContext, &handle);
}
