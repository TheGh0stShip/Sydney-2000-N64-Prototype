extern void func_800971EC(void *a, void *b, float c, void *d, int e, int f);
extern void func_800CEE04(void *obj);
extern void func_80096860(void *a, int b, int c, int d);
extern void func_80096C8C(void *a, int b, int c, void *d, int e, int f);
extern void func_80096F54(void *a, int b, int c);

typedef struct {
    int value;
    int pad[2];
} Score;

typedef struct {
    unsigned char pad0[2560];
    int mode;
    int subMode;
    unsigned char pad1[12];
    Score scores[63];
    unsigned char pad2[3344 - 2580 - 63 * 12];
    int sound;
} Globals;

extern Globals *D_800FC270;

static __inline__ int IsActive(unsigned char *p)
{
    int r = 0;

    if (p[426] == 1) {
        goto yes;
    }
    if (p[426] != 2) {
        goto done;
    }
yes:
    r = 1;
done:
    return r;
}

void func_8009A214(unsigned char *object)
{
    unsigned char *hi;
    unsigned char *anim;
    int active;
    int index;

    active = IsActive(*(unsigned char **)(object + 12136));
    if (active) {
        hi = object + 0x8000;
        if (hi[84] != 2) {
            anim = object + 15860;
            func_800971EC(anim, *(void **)(object + 12136), 0.6666f,
                          *(unsigned char **)(object + 12136) + 804, 195, -1);
            func_800CEE04(object + 14548);
            func_80096860(anim, 2, *(int *)(*(unsigned char **)(object + 12136) + 420), 0);
            index = (signed char)hi[81];
            func_80096C8C(anim, 2, D_800FC270->scores[index].value,
                          *(unsigned char **)(hi + 140) + index * 12,
                          (signed char)hi[80], 0);
            if (hi[84] == 4 || (D_800FC270->mode == 4 && D_800FC270->subMode == 1)) {
                func_80096F54(anim, 2, D_800FC270->sound);
            }
        }
    }
    *(int *)(object + 0x8000 + 124) = 0;
}
