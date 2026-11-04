/* Player message runtime preserved by the upstream libmus source. */
#include "mus_channel.h"

typedef struct {
    unsigned char type;
    int value;
} mus_msg_t;

extern int D_803AD9B4;
extern int D_803AD9B8;
extern int D_803AD9BC;
extern void *D_803AD9C0;
extern void *__MusIntMemMalloc(int size);
extern void func_800FDCCC(int value, int a, int b);
extern void ChangeCustomEffect(int value);

void func_800FBEB0(int count)
{
    if (count < 0x40)
        count = 0x40;
    else if (count > 0x400)
        count = 0x400;
    D_803AD9C0 = __MusIntMemMalloc(count * 8);
    D_803AD9BC = count;
    D_803AD9B8 = 0;
    D_803AD9B4 = 0;
}

void func_800FBF14(mus_msg_t *msg)
{
    switch (msg->type) {
    case 0:
        func_800FDCCC(msg->value, -2, 1);
        break;
    case 1:
        func_800FDCCC(msg->value, -2, 0);
        break;
    case 2:
        ChangeCustomEffect(msg->value);
        break;
    }
}
