typedef struct {
    unsigned short count;
    signed char n;
    unsigned char streak;
    unsigned int hist[4];
    unsigned int best;
    char pad[8];
} Entry;

typedef struct {
    char pad0[2];
    short score;
    float best;
    char pad8[4];
} Slot;

typedef struct { char pad[0xA10]; Slot slots[1]; } Global;
extern Global *D_800FC270;
extern const float D_80071370; /* 7.5f */

#define S(o) (obj + 0x8000 + (o))
#define E ((Entry *)*(int *)S(0x13C) + *(signed char *)S(0x11C))

void func_80075264(char *obj, unsigned int v)
{
    Slot *slot;
    Entry *e;
    int n;
    char *p = obj + 0x8000;


    slot = &D_800FC270->slots[*(signed char *)(p + 0x11C)];
    e = (Entry *)((*(signed char *)(p + 0x11C) << 5) + *(int *)(p + 0x13C));
    n = e->n;
    if (n >= 3) {
        e->hist[0] = e->hist[1];
        E->hist[1] = E->hist[2];
        E->hist[2] = v;
    } else {
        e->hist[n] = v;
    }
    if (v == 0) {
        E->count++;
        if ((unsigned char)(*(unsigned char *)S(0x11E) - 3) >= 2) {
            E->streak++;
        }
    } else {
        E->streak = 0;
    }
    if (E->best < v) {
        E->best = v;
        slot->best = v;
    }
    if (v >= 300) {
        E->streak = 3;
    }
    if (v != 0) {
        int s = (float)(unsigned int)(v - 100) * 7.5f;
        if (slot->score < s) {
            slot->score = s;
        }
    }
}
