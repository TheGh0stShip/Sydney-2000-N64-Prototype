#ifndef LEAF_NAME
#define LEAF_NAME releaseObjectIfFlagged
#endif
#ifndef CLEANUP_HELPER_NAME
#define CLEANUP_HELPER_NAME cleanupHelper
#endif
#ifndef RELEASE_HELPER_NAME
#define RELEASE_HELPER_NAME releaseHelper
#endif

extern void CLEANUP_HELPER_NAME(void *object);
extern void RELEASE_HELPER_NAME(void *object);

void LEAF_NAME(void *object, unsigned int flags) {
    CLEANUP_HELPER_NAME(object);
    if ((flags & 1) != 0) {
        RELEASE_HELPER_NAME(object);
    }
}
