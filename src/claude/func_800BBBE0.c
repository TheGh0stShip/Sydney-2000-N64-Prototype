typedef struct {
    int targetA;
    int targetB;
    int rateA;
    int rateB;
    signed char valueA;
    signed char valueB;
    short timerA;
    short timerB;
    char pad16[2];
} Channel;

typedef struct {
    int word0;
    int word4;
    union {
        signed char channel;
        int word;
    } u;
} InputEvent;

extern InputEvent runtimeInputEvents[];
extern volatile unsigned short runtimeInputReadIndex;
extern unsigned short runtimeInputWriteIndex;
extern Channel D_800F2AD8[];
extern unsigned char runtimeOutputContext[];
extern void func_800AB2A4(void *, int, int, int, int, int);

void func_800BBBE0(void) {
    InputEvent *ev = &runtimeInputEvents[runtimeInputReadIndex];
    for (;;) {
        int ch;
        int target;
        if (runtimeInputReadIndex == runtimeInputWriteIndex) {
            return;
        }
        ch = ev->u.channel;
        if (ch != 12) {
            target = D_800F2AD8[ch].targetA;
        } else {
            target = D_800F2AD8[ch].targetB;
        }
        if (target != 0) {
            int w = ev->u.word;
            if (ch != 12) {
                func_800AB2A4(runtimeOutputContext, ev->word4, 2, target, ev->word0, w);
            } else {
                func_800AB2A4(runtimeOutputContext, ev->word4, 1, target, ev->word0, w);
            }
        }
        runtimeInputReadIndex++;
        if (runtimeInputReadIndex < 0x100) {
            ev++;
        } else {
            runtimeInputReadIndex = 0;
            ev = runtimeInputEvents;
        }
    }
}
