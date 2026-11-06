/* Push a sample into the per-slot three-entry history and update the peak. */
typedef struct {
    unsigned char pad0[2];
    short scaled;
    float peak;
    unsigned char pad8[4];
} PeakRec;

typedef struct {
    float v[3];
} Hist3;

typedef struct {
    unsigned char pad0[0xA10];
    PeakRec recs[1];
} PeakTable;

typedef struct {
    unsigned char pad0[0x7CAC];
    signed char count;
    signed char slot;
    unsigned char pad7CAE[0x7CE4 - 0x7CAE];
    Hist3 *hist;
} PeakOwner;

extern PeakTable *D_800FC270;

void func_80074C58(PeakOwner *p, float v)
{
    PeakRec *r = &D_800FC270->recs[p->slot];

    if (p->count >= 3) {
        p->hist[p->slot].v[0] = p->hist[p->slot].v[1];
        p->hist[p->slot].v[1] = p->hist[p->slot].v[2];
        p->hist[p->slot].v[2] = v;
    } else {
        ((float *)p->hist)[p->slot * 3 + p->count] = v;
    }
    if (r->peak < v) {
        r->peak = v;
    }
    if (r->peak > 0.0f) {
        r->scaled = (short)(r->peak * *(float *)0x8007159C) * 65 / 10;
    }
}
