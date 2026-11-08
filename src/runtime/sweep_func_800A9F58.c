typedef struct { unsigned short f0; unsigned char pad2; unsigned char f3; unsigned short f4; unsigned short f6; } Info;
typedef struct { unsigned char pad0; unsigned char next; unsigned short threshold; } Option;
typedef struct { Info *info; Option **options; } Slot;
typedef struct { Slot *slots; unsigned char count; signed char sel; } Set;
extern unsigned int D_800F2714;
static inline unsigned short rnd(unsigned int n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}
unsigned short func_800A9F58(Set *s, unsigned char *out)
{
    unsigned char j;
    unsigned char r;
    signed char old;
    Option *opt;
    r = rnd(100) + 1;
    old = s->sel;
    s->sel = -1;
    j = 0;
    do {
        if (s->slots[old].info->f6 == 0) {
            s->sel = old;
            return 22;
        }
        opt = s->slots[old].options[j];
        if (opt->threshold >= r) {
            s->sel = opt->next;
        } else {
            j++;
            r -= opt->threshold;
        }
    } while (s->sel == -1);
    *out = s->slots[s->sel].info->f3;
    return s->slots[s->sel].info->f0;
}
