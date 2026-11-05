/* Runtime-stage C reconstruction: snapshot the 13 channel records into a caller-provided array. */
typedef struct {
    int targetA;          /* 0x00 */
    int targetB;          /* 0x04 */
    int rateA;            /* 0x08 */
    int rateB;            /* 0x0C */
    signed char valueA;   /* 0x10 */
    signed char valueB;   /* 0x11 */
    short timerA;         /* 0x12 */
    short timerB;         /* 0x14 */
    char pad16[2];
} Channel;
typedef char assert_channel_size[(sizeof(Channel) == 0x18) ? 1 : -1];

typedef struct {
    int targetA;          /* 0x00 */
    int targetB;          /* 0x04 */
    int rateA;            /* 0x08 */
    int rateB;            /* 0x0C */
    signed char valueA;   /* 0x10 */
    signed char valueB;   /* 0x11 */
    char pad12[2];
} ChannelState;
typedef char assert_state_size[(sizeof(ChannelState) == 0x14) ? 1 : -1];

extern Channel D_800F2AD8[];

void func_800BBD14(int unused, ChannelState *out) {
    unsigned int i;
    for (i = 0;;) {
        ChannelState *o = out;
        if (!(i < 13)) return;
        o->targetA = D_800F2AD8[i].targetA;
        o->targetB = D_800F2AD8[i].targetB;
        {
            int a = D_800F2AD8[i].valueA;
            o->valueA = a;
        }
        {
            int b = D_800F2AD8[i].valueB;
            o->valueB = b;
        }
        o->rateA = D_800F2AD8[i].rateA;
        o->rateB = D_800F2AD8[i].rateB;
        out++;
        i++;
    }
}
