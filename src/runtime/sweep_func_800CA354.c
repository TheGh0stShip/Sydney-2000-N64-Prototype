typedef struct { int ptr; char pad[212 - 4]; } Slot;
typedef struct {
    char pad0[0x114C];
    int lo[20];
    int hi[20];
    float max;
    float cur;
    int src;
    float ratio;
    float a;
    float b;
} Meter;

extern float func_800BB8C0(int src);

typedef struct { char pad[0x180]; Slot s[20]; } SlotHdr;
#define SLOTS(m) (((SlotHdr *)(m))->s)

void func_800CA354(Meter *m)
{
    unsigned char i;
    unsigned char n;

    if (m->src) {
        m->cur = func_800BB8C0(m->src);
    }
    if (m->cur > m->max) {
        m->cur = m->max;
    }
    if (m->max != 1.0f) {
        m->ratio = m->cur / m->max;
    } else {
        m->ratio = m->cur;
    }
    if (m->ratio < 0.0f) {
        m->ratio = 0.0f;
    }
    m->b = m->a;
    n = m->ratio * 20.0f;
    for (i = 0; i < n; i++) {
        SLOTS(m)[i].ptr = m->hi[i];
    }
    for (i = n; i < 20; i++) {
        SLOTS(m)[i].ptr = m->lo[i];
    }
}
