#ifndef LEAF_NAME
#define LEAF_NAME resetAndClearBuffers
#endif
#ifndef RESET_HELPER_NAME
#define RESET_HELPER_NAME resetHelper
#endif
#ifndef CLEAR_HELPER_NAME
#define CLEAR_HELPER_NAME clearHelper
#endif
#ifndef FIRST_BUFFER_NAME
#define FIRST_BUFFER_NAME firstBuffer
#endif
#ifndef SECOND_BUFFER_NAME
#define SECOND_BUFFER_NAME secondBuffer
#endif

extern unsigned char FIRST_BUFFER_NAME[];
extern unsigned char SECOND_BUFFER_NAME[];
extern void RESET_HELPER_NAME(void);
extern void CLEAR_HELPER_NAME(void *buffer, int value, int size);

void LEAF_NAME(void) {
    RESET_HELPER_NAME();
    CLEAR_HELPER_NAME(FIRST_BUFFER_NAME, 0, 0x800);
    CLEAR_HELPER_NAME(SECOND_BUFFER_NAME, 0, 0x800);
}
