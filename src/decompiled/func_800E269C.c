#include "sydney_types.h"

/* Calls func_80080F10 on every non-null entry of an 8x10 pointer grid. */
typedef struct Obj {
    u8 pad0[0x4F10];
    void *unk_4F10[8][10];
} Obj;
extern void func_80080F10(void *p);

void func_800E269C(Obj *obj) {
    u8 i;
    u8 j;
    void *p;

    i = 0;
    while (1) {
        if (i >= 8) break;
        j = 0;
        while (1) {
            if (j >= 10) break;
            p = obj->unk_4F10[i][j];
            j++;
            if (p != NULL) {
                func_80080F10(p);
            }
        }
        i++;
    }
}
