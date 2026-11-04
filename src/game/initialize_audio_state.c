#ifndef LEAF_NAME
#define LEAF_NAME initializeAudioState
#endif
#ifndef CONFIGURE_HELPER_NAME
#define CONFIGURE_HELPER_NAME configureHelper
#endif
#ifndef FIRST_HELPER_NAME
#define FIRST_HELPER_NAME firstHelper
#endif
#ifndef SECOND_HELPER_NAME
#define SECOND_HELPER_NAME secondHelper
#endif
#ifndef THIRD_HELPER_NAME
#define THIRD_HELPER_NAME thirdHelper
#endif
#ifndef CONFIGURATION_NAME
#define CONFIGURATION_NAME configuration
#endif
#ifndef FIRST_OBJECT_NAME
#define FIRST_OBJECT_NAME firstObject
#endif
#ifndef SECOND_OBJECT_NAME
#define SECOND_OBJECT_NAME secondObject
#endif

extern char CONFIGURATION_NAME[];
extern char FIRST_OBJECT_NAME[];
extern char SECOND_OBJECT_NAME[];
extern void CONFIGURE_HELPER_NAME(void *configuration, int, int, int);
extern void FIRST_HELPER_NAME(void);
extern void SECOND_HELPER_NAME(void *object);
extern void THIRD_HELPER_NAME(void *object);

void LEAF_NAME(void) {
    CONFIGURE_HELPER_NAME(CONFIGURATION_NAME, 0x7FFF, 0x7FFF, 0x7FFF);
    FIRST_HELPER_NAME();
    SECOND_HELPER_NAME(FIRST_OBJECT_NAME);
    THIRD_HELPER_NAME(SECOND_OBJECT_NAME);
}
