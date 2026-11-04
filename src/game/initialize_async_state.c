#ifndef LEAF_NAME
#define LEAF_NAME initializeAsyncState
#endif

#ifndef BZERO_NAME
#define BZERO_NAME bzero
#endif

#ifndef CREATE_QUEUE_NAME
#define CREATE_QUEUE_NAME osCreateMesgQueue
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BZERO_NAME(void *address, u32 size);
extern void CREATE_QUEUE_NAME(void *queue, void *messages, int count);

void LEAF_NAME(u8 *state, u32 first, u32 second, u32 third, u32 fourth) {
    BZERO_NAME(state, 400);
    *(u16 *)(state + 358) = 40;
    *(u32 *)(state + 400) = fourth;
    *(u32 *)(state + 404) = first;
    *(u32 *)(state + 408) = second;
    *(u32 *)(state + 412) = third;
    *(u32 *)(state + 4520) = 0;
    CREATE_QUEUE_NAME(state + 4524, state + 4548, 1);
    if (first == 0 || fourth == 0) {
        *(u8 *)(state + 4573) = 0;
    } else {
        *(u8 *)(state + 4573) = 1;
    }
    *(u8 *)(state + 4572) = 0;
    *(u16 *)(state + 4512) = *(u32 *)(state + 4516) =
        *(u16 *)(state + 4514) = 0;
    *(u32 *)(state + 4552) = 0;
    *(u32 *)(state + 4560) = 0;
    *(u32 *)(state + 4556) = 0;
    *(u32 *)(state + 4568) = 0;
    *(u32 *)(state + 4564) = 0;
    *(u8 *)(state + 4574) = 2;
}
