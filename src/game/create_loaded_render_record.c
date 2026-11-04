#ifndef LEAF_NAME
#define LEAF_NAME createLoadedRenderRecord
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadNamedResource
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef RELOCATE_NAME
#define RELOCATE_NAME relocateAsset
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeLoadedObject
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureObjectVector
#endif
#ifndef ASSERT_NAME
#define ASSERT_NAME reportAssertion
#endif

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 state;
    u8 padding04[0x24];
    u32 flags;
    float first;
    float second;
    float third;
    u8 padding38[68];
} LoadedRenderObject;

typedef struct RuntimeRecord {
    u32 type;
    LoadedRenderObject *object;
    u32 active;
    LoadedRenderObject **objectAddress;
    float **vectorAddress;
} RuntimeRecord;

extern u32 runtimeRecordCount __asm__("D_8005AC7C");
extern RuntimeRecord runtimeRecords[] __asm__("D_8005ACD0");
extern void *memoryContext __asm__("D_8005A9E8");
extern char objectTag[] __asm__("D_80000AD4");
extern char addressTag[] __asm__("D_80000ADC");
extern char assertFile[] __asm__("D_80000B38");
extern char assertText[] __asm__("D_80000B50");

extern u32 LOAD_NAME(char *name, void **output, void *context, u32 mode);
extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern void RELOCATE_NAME(void *source);
extern void INITIALIZE_NAME(void *source, LoadedRenderObject *object);
extern void RELEASE_NAME(void *context, void **handle);
extern void CONFIGURE_NAME(LoadedRenderObject *object, float, float, float);
extern void ASSERT_NAME(char *file, u32 line, char *text);

LoadedRenderObject *LEAF_NAME(char *name, RuntimeRecord **output)
{
    void *loaded = 0;
    LoadedRenderObject *source;
    LoadedRenderObject *object = 0;
    RuntimeRecord *record;
    u32 index;

    if (runtimeRecordCount == 128) {
        ASSERT_NAME(assertFile, 1961, assertText);
    }

    for (index = 0; index < runtimeRecordCount; index++) {
        if (runtimeRecords[index].object == 0) {
            break;
        }
    }
    if (index == runtimeRecordCount) {
        runtimeRecordCount++;
    }

    if (!LOAD_NAME(name, &loaded, memoryContext, 1)) {
        return 0;
    }
    ALLOCATE_NAME(memoryContext, (void **)&object, 124, objectTag);
    object->state = 1;
    source = loaded;
    RELOCATE_NAME(loaded);
    INITIALIZE_NAME(loaded, object);
    RELEASE_NAME(memoryContext, &loaded);

    if (source->flags & 2) {
        object->first = 0.0f;
        object->second = 0.0f;
        object->third = 0.0f;
    } else {
        CONFIGURE_NAME(object, object->first, object->second, object->third);
    }

    record = &runtimeRecords[index];
    record->active = 1;
    record->objectAddress = 0;
    record->vectorAddress = 0;
    ALLOCATE_NAME(memoryContext, (void **)&record->objectAddress, 4, addressTag);
    ALLOCATE_NAME(memoryContext, (void **)&record->vectorAddress, 4, addressTag);
    *record->vectorAddress = &object->first;
    record->object = object;
    *record->objectAddress = object;
    *output = record;
    record->type = 60;
    return object;
}
