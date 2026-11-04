#ifndef LEAF_NAME
#define LEAF_NAME waitForFramebufferRelease
#endif

#ifndef GET_CURRENT_NAME
#define GET_CURRENT_NAME getCurrentFramebuffer
#endif

#ifndef GET_NEXT_NAME
#define GET_NEXT_NAME getNextFramebuffer
#endif

#ifndef SET_MASK_NAME
#define SET_MASK_NAME setInterruptMask
#endif

#ifndef RECEIVE_NAME
#define RECEIVE_NAME receiveMessage
#endif

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Waiter {
    struct Waiter *next;
    void *queue;
} Waiter;

extern void *GET_CURRENT_NAME(void);
extern void *GET_NEXT_NAME(void);
extern u32 SET_MASK_NAME(u32 mask);
extern void RECEIVE_NAME(void *queue, void **message, u32 flags);

void LEAF_NAME(void *argument, void *task) {
    Waiter waiter;
    u8 *scheduler = argument;
    register Waiter *waiterPointer asm("$20") = &waiter;
    register void *queue asm("$21") = scheduler + 0x11c;
    register void *framebuffer asm("$22") = *(void **)((u8 *)task + 0xc);
    void *message = 0;
    register Waiter *current asm("$16");
    register Waiter *previous asm("$17");
    register Waiter *target asm("$18");
    u32 mask;
    u32 busy;

check_framebuffer:
        busy = 0;
        if (GET_CURRENT_NAME() == framebuffer) {
            goto framebuffer_busy;
        }
        if (GET_NEXT_NAME() != framebuffer) {
            goto framebuffer_ready;
        }

framebuffer_busy:
        busy = 1;

framebuffer_ready:
        if (busy == 0) {
            return;
        }

        mask = SET_MASK_NAME(1);
        waiterPointer->queue = queue;
        previous = 0;
        waiterPointer->next = *(Waiter **)(scheduler + 0x668);
        *(Waiter **)(scheduler + 0x668) = waiterPointer;
        SET_MASK_NAME(mask);

        RECEIVE_NAME(queue, &message, 1);

        current = *(Waiter **)(scheduler + 0x668);
        mask = SET_MASK_NAME(1);
        target = waiterPointer;
        while (current != 0) {
            if (current == target) {
                if (previous != 0) {
                    previous->next = current->next;
                } else {
                    *(Waiter **)(scheduler + 0x668) = current->next;
                }
                break;
            }
            previous = current;
            current = previous->next;
        }
        SET_MASK_NAME(mask);
        goto check_framebuffer;
}
