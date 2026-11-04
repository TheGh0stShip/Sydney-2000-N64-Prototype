#include <sched.h>

OSScTask* __scTaskReady(OSScTask* task) {
    void* current;
    void* next;

    if (task != 0) {
        current = osViGetCurrentFramebuffer();
        next = osViGetNextFramebuffer();
        if (current != next) {
            return 0;
        }

        return task;
    }

    return 0;
}
