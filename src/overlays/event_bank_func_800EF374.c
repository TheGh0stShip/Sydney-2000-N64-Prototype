typedef struct {
    int unk0;
    unsigned int period;
} EventTiming;

typedef struct {
    int unk0;
    unsigned char *config;
    char pad8[0x27E - 0x8];
    unsigned short phase;
    int next;
    char pad284[0x2DD - 0x284];
    unsigned char jitter;
} EventTimer;

extern int D_800F2778;
extern unsigned int D_800F2C14;
extern unsigned char *D_800FC270;
extern EventTiming D_8007BD20[];
extern EventTiming D_8007BD30;

unsigned short func_800EF374(EventTimer *t, int now)
{
    EventTiming *timing;
    unsigned int period;
    unsigned int seed;

    now -= D_800F2778;
    if (t->config[0x8417] == 2) {
        timing = &D_8007BD30;
    } else {
        timing = &D_8007BD20[D_800FC270[0xD53]];
    }
    if (now >= t->next) {
        if (t->phase & 1) { t->phase = 2; } else { t->phase = 1; }
        period = timing->period;
        if (t->jitter != 0) {
            seed = (D_800F2C14 * 16807) & 0x7FFFFFFF;
            period += (unsigned int)(period * (((seed >> 15) * t->jitter) >> 16)) / 100;
            D_800F2C14 = seed;
        }
        t->next += period;
    }
    return t->phase;
}
