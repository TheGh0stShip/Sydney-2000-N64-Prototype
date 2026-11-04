#ifndef LEAF_NAME
#define LEAF_NAME initializeWorkBuffers
#endif

#ifndef FIRST_SETUP_NAME
#define FIRST_SETUP_NAME firstSetup
#endif

#ifndef SECOND_SETUP_NAME
#define SECOND_SETUP_NAME secondSetup
#endif

#ifndef DELAY_NAME
#define DELAY_NAME delay
#endif

#ifndef FILL_NAME
#define FILL_NAME fillBytes
#endif

#ifndef FIRST_BUFFER_NAME
#define FIRST_BUFFER_NAME firstBuffer
#endif

#ifndef SECOND_BUFFER_NAME
#define SECOND_BUFFER_NAME secondBuffer
#endif

#ifndef INITIALIZED_NAME
#define INITIALIZED_NAME initialized
#endif

typedef unsigned char u8;
typedef signed int s32;

extern u8 FIRST_BUFFER_NAME[2048];
extern u8 SECOND_BUFFER_NAME[2048];
extern s32 INITIALIZED_NAME;

extern void FIRST_SETUP_NAME(void);
extern void SECOND_SETUP_NAME(void);
extern void DELAY_NAME(void);
extern void FILL_NAME(void *destination, s32 value, s32 length);

s32 LEAF_NAME(void) {
    FIRST_SETUP_NAME();
    SECOND_SETUP_NAME();
    DELAY_NAME();
    FILL_NAME(FIRST_BUFFER_NAME, 0, 2048);
    FILL_NAME(SECOND_BUFFER_NAME, 0, 2048);
    if (INITIALIZED_NAME == 0) {
        INITIALIZED_NAME = 1;
    }
    return 0;
}
