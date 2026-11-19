#include "sydney_types.h"

/* Walks two static arrays from end to start with empty bodies (trivial array destructors). */
typedef struct { u8 unk_00[0x18]; } S18;
typedef struct { u8 unk_00[0x8]; } S8;
extern S18 D_800F2AD8[13];
extern S8 D_800F2A70[13];

void func_800BC008(void) {
    volatile s32 pad[4];
    S18 *p;
    S8 *q;

    if (D_800F2AD8 != NULL) {
        S18 *b = D_800F2AD8;
        p = b + 13;
        while (b != p) {
            p--;
        }
    }
    if (D_800F2A70 != NULL) {
        q = D_800F2A70 + 13;
        while (q != D_800F2A70) {
            q--;
        }
    }
}
