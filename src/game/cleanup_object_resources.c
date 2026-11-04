#ifndef LEAF_NAME
#define LEAF_NAME cleanupObjectResources
#endif

#ifndef RELEASE_SLOT_NAME
#define RELEASE_SLOT_NAME releaseSlot
#endif

#ifndef RELEASE_OBJECT_NAME
#define RELEASE_OBJECT_NAME releaseObject
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 objectCleanupBlocked;
extern u8 commandContext[];
extern void RELEASE_SLOT_NAME(void *context, void *slot);
extern void RELEASE_OBJECT_NAME(void *object);

void LEAF_NAME(u8 *object) {
    if (objectCleanupBlocked != 0) {
        return;
    }
    if (*(u32 *)(object + 80) != 0) {
        RELEASE_SLOT_NAME(commandContext, object + 80);
    }
    if (*(u32 *)(object + 72) != 0) {
        RELEASE_SLOT_NAME(commandContext, object + 72);
    }
    if (*(u32 *)(object + 76) != 0) {
        RELEASE_SLOT_NAME(commandContext, object + 76);
    }
    if (*(u32 *)(object + 84) != 0) {
        RELEASE_SLOT_NAME(commandContext, object + 84);
    }

    if (*(u8 **)(object + 56) != 0) {
        LEAF_NAME(*(u8 **)(object + 56));
        object = *(u8 **)(object + 56);
        if (object != 0) {
            LEAF_NAME(object);
            RELEASE_OBJECT_NAME(object);
        }
    }
}
