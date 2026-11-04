#ifndef LEAF_NAME
#define LEAF_NAME allocatePlayerScratch
#endif

#ifndef COUNT_NAME
#define COUNT_NAME allocationCount
#endif

#ifndef PLAYER_NAME
#define PLAYER_NAME currentPlayer
#endif

#ifndef BUFFER_NAME
#define BUFFER_NAME scratchBuffer
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 COUNT_NAME;
extern u32 PLAYER_NAME;
extern u8 BUFFER_NAME[];

void *LEAF_NAME(void) {
    u32 allocation = COUNT_NAME;
    u8 *playerBuffer;

    if (allocation >= 128) {
        return BUFFER_NAME + PLAYER_NAME * 64;
    }
    COUNT_NAME = allocation + 1;
    playerBuffer = BUFFER_NAME + PLAYER_NAME * 64;
    return playerBuffer + allocation * 128;
}
