#include "sydney_types.h"

/* Releases every allocated slot (up to 8) and marks it free. */
typedef struct Mgr {
    u8 unk_00[0x547C];
    s8 slotId[8];
    void *slotPtr[8];
} Mgr;

void func_8001786C(void *p);

void func_80087E68(Mgr *mgr) {
    u8 i = 0;

    while (1) {
        if (i >= 8) break;
        if (mgr->slotId[i] != -1) {
            func_8001786C(mgr->slotPtr[i]);
            mgr->slotPtr[i] = NULL;
            mgr->slotId[i] = -1;
        }
        i++;
    }
}
