/* Core handle controls preserved by the upstream libmus source. */
#include "mus_channel.h"

int func_800FB7D4(int handle, int speed)
{
    int i;
    int count;
    channel_t *cp;
    int speed2;

    if (handle == 0)
        return 0;
    speed2 = speed;
    if (speed == 0)
        speed2 = 1;
    count = 0;
    for (i = 0, cp = D_803AD97C; i < D_803AD974; i++, cp++) {
        if (cp->handle == handle && cp->stopping == -1) {
            if (cp->flags & 1) {
                cp->stopping_speed = 1;
                cp->stopping = 0;
                cp->flags &= ~1;
            } else {
                cp->stopping_speed = speed2;
                cp->stopping = speed;
            }
            count++;
        }
    }
    return count;
}

int func_800FB888(int handle)
{
    channel_t *cp;
    int count;
    int i;

    if (handle == 0)
        return 0;
    count = 0;
    for (i = 0, cp = D_803AD97C; i < D_803AD974; i++, cp++)
        count += cp->handle == handle;
    return count;
}

int func_800FB8E0(int handle, int speed)
{
    int i;
    int count;
    channel_t *cp;

    if (handle == 0)
        return 0;
    count = 0;
    for (i = 0, cp = D_803AD97C; i < D_803AD974; i++, cp++) {
        if (cp->handle == handle) {
            cp->temscale = speed;
            count++;
        }
    }
    return count;
}
