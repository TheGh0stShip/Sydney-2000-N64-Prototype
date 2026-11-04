#ifndef LEAF_NAME
#define LEAF_NAME loadNamedRecordData
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeLookup
#endif
#ifndef COPY_STRING_NAME
#define COPY_STRING_NAME copyString
#endif
#ifndef FIND_NAME
#define FIND_NAME findRecord
#endif
#ifndef CHECK_NAME
#define CHECK_NAME checkRecordSignature
#endif
#ifndef GET_SIZE_NAME
#define GET_SIZE_NAME getRecordPayloadSize
#endif
#ifndef COPY_RECORD_NAME
#define COPY_RECORD_NAME copyRecord
#endif
#ifndef LOAD_SPECIAL_NAME
#define LOAD_SPECIAL_NAME loadSpecialRecord
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadResourcePayload
#endif
#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupLookup
#endif

typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u32 first;
    s32 index;
} RecordLookup;

extern u32 resourceLookupBusy __asm__("D_80043714");
extern char allocationTag[] __asm__("D_80000510");

extern void INITIALIZE_NAME(RecordLookup *lookup);
extern void COPY_STRING_NAME(char *destination, const char *source);
extern s32 FIND_NAME(RecordLookup *lookup, const char *name, u32 limit);
extern s32 CHECK_NAME(RecordLookup *lookup, s32 index);
extern s32 GET_SIZE_NAME(RecordLookup *lookup, s32 index);
extern s32 COPY_RECORD_NAME(RecordLookup *lookup, s32 index);
extern s32 LOAD_SPECIAL_NAME(RecordLookup *lookup, s32 index, void **output);
extern s32 ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern s32 LOAD_NAME(RecordLookup *lookup, s32 index, void *output);
extern void CLEANUP_NAME(RecordLookup *lookup, s32 *index);

s32 LEAF_NAME(const char *name, void **output, void *memoryContext)
{
    char copiedName[256];

    RecordLookup lookup;

    s32 result;

    s32 size;

    resourceLookupBusy = 1;
    INITIALIZE_NAME(&lookup);
    COPY_STRING_NAME(copiedName, name);
    lookup.index = FIND_NAME(&lookup, copiedName, 16);
    if (lookup.index < 0) {
        resourceLookupBusy = 0;
        return 0;
    }

    if (*output == 0) {
        if (CHECK_NAME(&lookup, lookup.index) == 1) {
            size = GET_SIZE_NAME(&lookup, lookup.index);
        } else {
            size = COPY_RECORD_NAME(&lookup, lookup.index);
        }

        if (CHECK_NAME(&lookup, lookup.index) == 1) {
            resourceLookupBusy = 0;
            result = LOAD_SPECIAL_NAME(&lookup, lookup.index, output);
            if (result == -1) {
                resourceLookupBusy = 0;
                return 0;
            }
        } else {
            result = ALLOCATE_NAME(memoryContext, output, size, allocationTag);
            if (result != 0) {
                return 0;
            }
            resourceLookupBusy = 0;
            result = LOAD_NAME(&lookup, lookup.index, *output);
            if (result == -1) {
                resourceLookupBusy = 0;
                return 0;
            }
        }
    }

    CLEANUP_NAME(&lookup, &lookup.index);
    resourceLookupBusy = 0;
    return size;
}
