#ifndef LEAF_NAME
#define LEAF_NAME createSkeletonRenderRecord
#endif
#ifndef LENGTH_NAME
#define LENGTH_NAME stringLength
#endif
#ifndef COPY_NAME
#define COPY_NAME copyString
#endif
#ifndef APPEND_NAME
#define APPEND_NAME appendString
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadNamedResource
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef BUILD_NAME
#define BUILD_NAME buildSkeletonObject
#endif
#ifndef ASSERT_NAME
#define ASSERT_NAME reportAssertion
#endif

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct RuntimeRecord {
    u32 type;
    void *object;
    u32 active;
    void **objectAddress;
    void **auxiliaryAddress;
} RuntimeRecord;

extern u32 runtimeRecordCount __asm__("D_8005AC7C");
extern u32 currentSkeletonType __asm__("D_8005ACAC");
extern RuntimeRecord runtimeRecords[] __asm__("D_8005ACD0");
extern char *skeletonTypeSuffixes[] __asm__("D_8005A968");
extern void *memoryContext __asm__("D_8005A9E8");
extern void *resourceContext __asm__("D_8005AC88");
extern char animationName[] __asm__("D_8006A450");
extern char addressTag[] __asm__("D_80000ADC");
extern char assertFile[] __asm__("D_80000B38");
extern char assertText[] __asm__("D_80000B50");
extern char animationSuffix[4] __asm__("D_80000B78");
extern char placeholderTag[] __asm__("D_80000B7C");
extern char missingSkeletonText[] __asm__("D_80000B84");

extern u32 LENGTH_NAME(char *text);
extern void COPY_NAME(char *destination, char *source);
extern void APPEND_NAME(char *destination, char *source);
extern u32 LOAD_NAME(char *name, void **output, void *context, u32 mode);
extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern void RELEASE_NAME(void *context, void **handle);
extern void *BUILD_NAME(void *skeleton, void *parameter, void *animation);
extern void ASSERT_NAME(char *file, u32 line, char *text);

void *LEAF_NAME(char *name, int type, void *parameter)
{
    void *skeleton = 0;
    void *animation = 0;
    void *placeholder = 0;
    RuntimeRecord *record;
    void *object;
    u32 count;
    u32 slot;
    u32 index;
    u32 separators;
    u32 hasSuffix;
    char *end;

    if (runtimeRecordCount == 128) {
        ASSERT_NAME(assertFile, 1961, assertText);
    }

    count = runtimeRecordCount;
    slot = count;
    for (index = 0; index < count; index++) {
        if (runtimeRecords[index].object == 0) {
            slot = index;
        }
    }
    if (slot == runtimeRecordCount) {
        runtimeRecordCount = slot + 1;
    }

    /* Some skeleton types share a base model: strip the trailing three
       underscore-separated name parts and append the type suffix. */
    currentSkeletonType = type;
    if (type >= 0) {
        switch (type) {
        case 1:
        case 2:
        case 5:
        case 7:
        case 12:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 27:
        case 29:
        case 30:
            hasSuffix = 1;
            break;
        default:
            hasSuffix = 0;
            break;
        }
        if (hasSuffix) {
            separators = 0;
            for (index = LENGTH_NAME(name) - 1; index != 0; index--) {
                if (name[index] == '_') {
                    separators++;
                }
                if (separators == 3) {
                    name[index] = 0;
                    APPEND_NAME(name, skeletonTypeSuffixes[currentSkeletonType]);
                    break;
                }
            }
        }
    }

    /* The animation shares the skeleton name with its last three
       characters replaced. */
    COPY_NAME(animationName, name);
    end = animationName + LENGTH_NAME(animationName);
    __builtin_memcpy(end - 3, animationSuffix, 4);
    if (LOAD_NAME(animationName, &animation, resourceContext, 1) == 0) {
        animation = 0;
    }

    ALLOCATE_NAME(memoryContext, &placeholder, 0x10000, placeholderTag);
    if (LOAD_NAME(name, &skeleton, resourceContext, 1) == 0) {
        ASSERT_NAME(assertFile, 2185, missingSkeletonText);
    }
    RELEASE_NAME(memoryContext, &placeholder);

    record = &runtimeRecords[slot];
    record->active = 1;
    record->objectAddress = 0;
    record->auxiliaryAddress = 0;
    ALLOCATE_NAME(memoryContext, (void **)&record->objectAddress, 4, addressTag);
    ALLOCATE_NAME(memoryContext, (void **)&record->auxiliaryAddress, 4, addressTag);

    object = BUILD_NAME(skeleton, parameter, animation);
    if (animation != 0) {
        RELEASE_NAME(memoryContext, &animation);
    }
    record->object = object;
    *record->objectAddress = object;
    record->type = 90;
    return object;
}
