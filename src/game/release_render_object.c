#ifndef LEAF_NAME
#define LEAF_NAME releaseRenderObject
#endif
#ifndef RELEASE_HANDLE_NAME
#define RELEASE_HANDLE_NAME releaseHandle
#endif
#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupObjectResources
#endif
#ifndef RELEASE_OBJECT_NAME
#define RELEASE_OBJECT_NAME releaseObject
#endif
#ifndef CONTEXT_NAME
#define CONTEXT_NAME memoryContext
#endif
#ifndef ROOT_NAME
#define ROOT_NAME rootRenderObject
#endif
#ifndef BLOCKED_NAME
#define BLOCKED_NAME objectCleanupBlocked
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RenderObject RenderObject;
struct RenderObject {
    u8 padding00[0x38];
    RenderObject *child;
    u8 padding3C[0x0C];
    void *handle48;
    void *handle4C;
    void *handle50;
    void *handle54;
};

extern u8 CONTEXT_NAME[];
extern RenderObject ROOT_NAME;
extern u32 BLOCKED_NAME;
extern void RELEASE_HANDLE_NAME(void *context, void **handle);
extern void CLEANUP_NAME(RenderObject *object);
extern void RELEASE_OBJECT_NAME(RenderObject *object);

u32 LEAF_NAME(RenderObject **slot) {
    RenderObject *object = *slot;
    RenderObject *child;

    if (object != &ROOT_NAME) {
        if (BLOCKED_NAME == 0) {
            if (object->handle50 != 0) {
                RELEASE_HANDLE_NAME(CONTEXT_NAME, &object->handle50);
            }
            if (object->handle48 != 0) {
                RELEASE_HANDLE_NAME(CONTEXT_NAME, &object->handle48);
            }
            if (object->handle4C != 0) {
                RELEASE_HANDLE_NAME(CONTEXT_NAME, &object->handle4C);
            }
            if (object->handle54 != 0) {
                RELEASE_HANDLE_NAME(CONTEXT_NAME, &object->handle54);
            }
            if (object->child != 0) {
                CLEANUP_NAME(object->child);
                child = object->child;
                if (child != 0) {
                    CLEANUP_NAME(child);
                    RELEASE_OBJECT_NAME(child);
                }
            }
        }
        RELEASE_HANDLE_NAME(CONTEXT_NAME, (void **)slot);
    }
    return 0;
}
