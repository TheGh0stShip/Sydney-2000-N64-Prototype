typedef struct Entry { short pad0; short level; float peak; int pad8; } Entry;
typedef struct Meter {
    char pad[0x8414]; signed char sub; signed char idx; char pad416;
    unsigned char state; char pad418[0x34]; float *hist;
} Meter;
extern char *D_800FC270;
void func_8008D11C(Meter *m, float value)
{
    if (m->state != 5) {
        Entry *e = (Entry *)(D_800FC270 + 0xA10 + (m->idx * 3) * 4);
        if (m->sub >= 3) {
            m->hist[m->idx * 3 + 0] = m->hist[m->idx * 3 + 1];
            m->hist[m->idx * 3 + 1] = m->hist[m->idx * 3 + 2];
            m->hist[m->idx * 3 + 2] = value;
            goto done;
        } else {
            m->hist[m->idx * 3 + m->sub] = value;
            if (e->peak < value) e->peak = value;
            if (0.0f < e->peak) e->level = e->peak * *(float *)0x8007135C;
        }
    }
done:
    return;
}
