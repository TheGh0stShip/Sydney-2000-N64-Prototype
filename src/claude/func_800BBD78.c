/* Runtime-stage C reconstruction: set one (or every) channel's A/B target pair and clear its timer. */
typedef struct {
    int targetA;          /* 0x00 */
    int targetB;          /* 0x04 */
    int rateA;            /* 0x08 */
    int rateB;            /* 0x0C */
    unsigned char valueA; /* 0x10 */
    unsigned char valueB; /* 0x11 */
    short timerA;         /* 0x12 */
    short timerB;         /* 0x14 */
    char pad16[2];
} Channel;

void func_800BBD78(Channel *channels, int index, int which, int target, int rate) {
    unsigned int i;
    if (index < 13) {
        if (which == 0) {
            channels[index].targetA = target;
            channels[index].rateA = rate;
            channels[index].timerA = 0;
        } else {
            channels[index].targetB = target;
            channels[index].rateB = rate;
            channels[index].timerB = 0;
        }
        return;
    }
    if (which == 0) {
        for (i = 0;;) {
            if (!(i < 12)) return;
            channels[i].targetA = target;
            channels[i].rateA = rate;
            channels[i].timerA = 0;
            i++;
        }
    } else {
        for (i = 0;;) {
            if (!(i < 12)) return;
            channels[i].targetB = target;
            channels[i].rateB = rate;
            channels[i].timerB = 0;
            i++;
        }
    }
}
