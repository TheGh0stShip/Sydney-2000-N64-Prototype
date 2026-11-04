#ifndef LEAF_NAME
#define LEAF_NAME resolveResourceData
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeLookup
#endif
#ifndef FIND_NAME
#define FIND_NAME findLookupEntry
#endif
#ifndef CHECK_NAME
#define CHECK_NAME checkEntrySignature
#endif
#ifndef PAYLOAD_NAME
#define PAYLOAD_NAME getEntryPayload
#endif
#ifndef RECORD_NAME
#define RECORD_NAME getEntryRecord
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareResourceOutput
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadResourceData
#endif
#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupLookup
#endif

typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u32 word;
} ResourceLookup;

extern u32 resourceLookupBusy __asm__("D_80043714");
extern char resourceDataTag[] __asm__("D_8000051C");

extern void INITIALIZE_NAME(ResourceLookup *lookup);
extern s32 FIND_NAME(ResourceLookup *lookup, char *name, u32 length);
extern s32 CHECK_NAME(ResourceLookup *lookup, s32 index);
extern u32 PAYLOAD_NAME(ResourceLookup *lookup, s32 index);
extern u32 RECORD_NAME(ResourceLookup *lookup, s32 index);
extern s32 PREPARE_NAME(ResourceLookup *lookup, s32 index, void **output);
extern s32 ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern s32 LOAD_NAME(ResourceLookup *lookup, s32 index, void *output);
extern void CLEANUP_NAME(ResourceLookup *lookup, s32 *index);

u32 LEAF_NAME(char *name, void **output, void *context)
{
    ResourceLookup lookup;
    s32 index;
    u32 size;

    resourceLookupBusy = 1;
    INITIALIZE_NAME(&lookup);
    index = FIND_NAME(&lookup, name, 16);
    if (index < 0) {
        resourceLookupBusy = 0;
        return 0;
    }

    if (*output == 0) {
        if (CHECK_NAME(&lookup, index) == 1) {
            size = PAYLOAD_NAME(&lookup, index);
        } else {
            size = RECORD_NAME(&lookup, index);
        }

        if (CHECK_NAME(&lookup, index) == 1) {
            resourceLookupBusy = 0;
            if (PREPARE_NAME(&lookup, index, output) == -1) {
                resourceLookupBusy = 0;
                return 0;
            }
        } else {
            if (ALLOCATE_NAME(context, output, size, resourceDataTag) != 0) {
                return 0;
            }
            resourceLookupBusy = 0;
        }
    }

    if (LOAD_NAME(&lookup, index, *output) == -1) {
        resourceLookupBusy = 0;
        return 0;
    }
    CLEANUP_NAME(&lookup, &index);
    resourceLookupBusy = 0;
    return size;
}
