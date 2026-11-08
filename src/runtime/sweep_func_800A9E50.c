typedef struct { unsigned short f0; unsigned char pad2; unsigned char f3; unsigned short f4; } Info;
typedef struct { Info *info; int pad; } Slot;
typedef struct { Slot *slots; unsigned char count; signed char sel; } Set;
extern unsigned char D_800F2570[];
extern unsigned int D_800F2714;
static inline unsigned short rnd(unsigned int n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}
unsigned short func_800A9E50(Set *s, unsigned char *out)
{
    unsigned char i;
    unsigned char n = 0;
    for (i = 0; i < s->count; i++) {
        if (s->slots[i].info->f4 == 1) {
            D_800F2570[n] = i;
            n++;
        }
    }
    s->sel = D_800F2570[rnd(n)];
    *out = s->slots[s->sel].info->f3;
    return s->slots[s->sel].info->f0;
}
