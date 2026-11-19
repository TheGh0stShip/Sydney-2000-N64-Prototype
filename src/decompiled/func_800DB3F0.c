#include "sydney_types.h"

/* Releases up to eight slot handles, marking each slot free (-1). */
typedef struct { u8 unk_0[0x61B4]; s8 slot[8]; void *handle[8]; } Mgr;
void func_8001786C(void *h);
void func_800DB3F0(Mgr *m) {
    u8 i = 0;
    while (1) {
        if (i >= 8) break;
        if (m->slot[i] != -1) {
            func_8001786C(m->handle[i]);
            m->handle[i] = NULL;
            m->slot[i] = -1;
        }
        i++;
    }
}
