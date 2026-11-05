/* Runtime-stage C reconstruction: latch one (or every) channel's A/B value and clear its timer. */
typedef struct {
    char pad0[0x10];
    unsigned char valueA; /* 0x10 */
    unsigned char valueB; /* 0x11 */
    short timerA;         /* 0x12 */
    short timerB;         /* 0x14 */
    char pad16[2];
} Channel;

void func_800BC1E8(Channel *channels, int index, int which, int value) {
    unsigned int i;
    if (index < 13) {
        if (which == 0) {
            channels[index].valueA = value;
            channels[index].timerA = 0;
        } else {
            channels[index].valueB = value;
            channels[index].timerB = 0;
        }
        return;
    }
    if (which == 0) {
        for (i = 0;;) {
            if (!(i < 12)) return;
            channels[i].valueA = value;
            channels[i].timerA = 0;
            i++;
        }
    } else {
        for (i = 0;;) {
            if (!(i < 12)) return;
            channels[i].valueB = value;
            channels[i].timerB = 0;
            i++;
        }
    }
}
