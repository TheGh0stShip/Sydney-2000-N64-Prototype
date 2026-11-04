#include "PR/os_internal.h"

OSThread* __osPopThread(OSThread** queue) {
    OSThread* thread = *queue;
    register OSThread* next __asm__("$25");

    next = thread->next;
    *queue = next;
    return thread;
}
