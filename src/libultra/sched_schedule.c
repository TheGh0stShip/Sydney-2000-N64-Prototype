#include <sched.h>

#define OS_SC_DP 0x0001
#define OS_SC_SP 0x0002
#define OS_SC_YIELDED 0x0020

#define OS_SC_XBUS (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS OS_SC_SP
#define OS_SC_DP_DRAM (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS OS_SC_DP
#define OS_SC_SP_DRAM (OS_SC_DP | OS_SC_DRAM_DLIST)

static __inline__ OSScTask* scTaskReadyInline(OSScTask* task) {
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

s32 __scSchedule(OSSched* sched, OSScTask** sp, OSScTask** dp, s32 availRCP) {
    s32 avail = availRCP;
    OSScTask* gfx = sched->gfxListHead;
    OSScTask* audio = sched->audioListHead;

    if (sched->doAudio && (avail & OS_SC_SP)) {
        if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK)) {
            *sp = gfx;
            avail &= ~OS_SC_SP;
        } else {
            *sp = audio;
            avail &= ~OS_SC_SP;
            sched->doAudio = 0;
            sched->audioListHead = sched->audioListHead->next;
            if (sched->audioListHead == 0) {
                sched->audioListTail = 0;
            }
        }
    } else if (scTaskReadyInline(gfx)) {
        switch (gfx->flags & OS_SC_TYPE_MASK) {
            case OS_SC_XBUS:
                if (gfx->state & OS_SC_YIELDED) {
                    if (avail & OS_SC_SP) {
                        *sp = gfx;
                        avail &= ~OS_SC_SP;

                        if (gfx->state & OS_SC_DP) {
                            *dp = gfx;
                            avail &= ~OS_SC_DP;
                        }

                        sched->gfxListHead = sched->gfxListHead->next;
                        if (sched->gfxListHead == 0) {
                            sched->gfxListTail = 0;
                        }
                    }
                } else if (avail == (OS_SC_SP | OS_SC_DP)) {
                    *sp = *dp = gfx;
                    avail &= ~(OS_SC_SP | OS_SC_DP);
                    sched->gfxListHead = sched->gfxListHead->next;
                    if (sched->gfxListHead == 0) {
                        sched->gfxListTail = 0;
                    }
                }
                break;

            case OS_SC_DRAM:
            case OS_SC_DP_DRAM:
            case OS_SC_DP_XBUS:
                if (gfx->state & OS_SC_SP) {
                    if (avail & OS_SC_SP) {
                        *sp = gfx;
                        avail &= ~OS_SC_SP;
                    }
                } else if (gfx->state & OS_SC_DP) {
                    if (avail & OS_SC_DP) {
                        *dp = gfx;
                        avail &= ~OS_SC_DP;
                        sched->gfxListHead = sched->gfxListHead->next;
                        if (sched->gfxListHead == 0) {
                            sched->gfxListTail = 0;
                        }
                    }
                }
                break;

            case OS_SC_SP_DRAM:
            case OS_SC_SP_XBUS:
            default:
                break;
        }
    }

    if (avail != availRCP) {
        avail = __scSchedule(sched, sp, dp, avail);
    }

    return avail;
}
