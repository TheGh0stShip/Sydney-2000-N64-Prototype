#ifndef LEAF_NAME
#define LEAF_NAME registerRuntimeObject
#endif
#ifndef CHECK_NAME
#define CHECK_NAME checkRuntimeObject
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeObjectBuffers
#endif
#ifndef UPDATE_NAME
#define UPDATE_NAME updateRuntimeRenderResource
#endif

typedef signed int s32;
typedef unsigned int u32;

typedef struct RuntimeObject {
    u32 type;
    unsigned char padding04[0xB4];
    struct RuntimeObject *next;
    struct RuntimeObject *previous;
    u32 flags;
    void *resource;
    u32 paddingC8;
    u32 playerMask;
} RuntimeObject;

typedef struct {
    unsigned char padding00[0x70];
    u32 firstCount;
    u32 secondCount;
    u32 specialCount;
    unsigned char padding7C[8];
} RuntimePlayerRecord;

extern RuntimeObject *specialObjects[] __asm__("D_8005AAC4");
extern u32 specialObjectCount __asm__("D_8005AAEC");
extern RuntimeObject *specialListTail __asm__("D_8005AAB4");
extern RuntimeObject *firstListTail __asm__("D_8005AAAC");
extern RuntimeObject *secondListTail __asm__("D_8005AAB0");
extern RuntimePlayerRecord runtimePlayerRecords[] __asm__("D_8005AAF0");
extern unsigned char renderResourceState[] __asm__("D_80065BB0");

extern u32 CHECK_NAME(RuntimeObject *);
extern void INITIALIZE_NAME(void *);
extern void UPDATE_NAME(RuntimeObject *, void *);

#define LINK_OBJECT(tail, object) do { \
    (object)->previous = *(tail); \
    if (*(tail) != 0) { \
        (*(tail))->next = (object); \
    } \
    *(tail) = (object); \
    (object)->next = (object); \
} while (0)

s32 LEAF_NAME(RuntimeObject *object)
{
    u32 player;

    if (object->next != 0 || object->previous != 0) {
        return -999;
    }
    if (object->type == 105) {
        specialObjects[specialObjectCount++] = object;
        return 0;
    }

    if (CHECK_NAME(object) != 0 && (object->flags & 0x01000000)) {
        INITIALIZE_NAME(object->resource);
    }
    if (object->type == 72) {
        UPDATE_NAME(object, renderResourceState);
    }

    if (object->flags & 0x80000078) {
        LINK_OBJECT(&specialListTail, object);
        for (player = 0; player < 3; player++) {
            if (object->playerMask & (1U << player)) {
                runtimePlayerRecords[player].specialCount++;
            }
        }
        return 0;
    }

    if (object->playerMask == 1) {
        if (object->flags & 0x00040000) {
            runtimePlayerRecords[0].firstCount++;
        } else {
            runtimePlayerRecords[0].secondCount++;
        }
    } else {
        for (player = 0; player < 3; player++) {
            if (object->playerMask & (1U << player)) {
                if (object->flags & 0x00040000) {
                    runtimePlayerRecords[player].firstCount++;
                } else {
                    runtimePlayerRecords[player].secondCount++;
                }
            }
        }
    }

    if (object->flags & 0x00040000) {
        LINK_OBJECT(&firstListTail, object);
        object->flags |= 0x00100000;
    } else {
        LINK_OBJECT(&secondListTail, object);
    }
    return 0;
}
