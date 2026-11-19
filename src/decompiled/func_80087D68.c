#include "sydney_types.h"

/* Loads a resource for an id into a free cache slot (8 slots of id + handle) and gives it to the object. */
typedef struct {
    u8 unk_0000[0x547C];
    s8 ids[8];
    void *handles[8];
} Cache;

typedef struct {
    u8 unk_000[0x2D8];
    void *unk_2D8;
} User;

extern s32 func_800DAC28(u8);
extern void *func_800140A0(void *, u8, s32);
extern void *D_8007749C[];

void func_80087D68(Cache *arg0, User *arg1, s32 arg2) {
    s8 slot = -1;
    u8 i;
    u8 missing = 1;

    for (i = 0; i < 8; i++) {
        if (arg0->ids[i] == -1) {
            if (slot == -1) {
                slot = i;
            }
        } else if (arg0->ids[i] == 0xFF) {
            missing = 0;
            break;
        }
    }
    if (!missing) {
        arg1->unk_2D8 = arg0->handles[i];
        return;
    }
    arg1->unk_2D8 = func_800140A0(D_8007749C[func_800DAC28(arg2)], arg2, 1);
    arg0->ids[slot] = arg2;
    arg0->handles[slot] = arg1->unk_2D8;
}
