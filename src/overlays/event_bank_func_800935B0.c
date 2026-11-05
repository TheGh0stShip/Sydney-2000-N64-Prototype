extern void func_800971EC(void *a, void *b, float c, void *d, int e, int f);
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

static __inline__ int IsPlayerActive(unsigned char *player)
{
    int active = 0;

    if (player[426] == 1) {
        goto yes;
    }
    if (player[426] != 2) {
        goto done;
    }
yes:
    active = 1;
done:
    return active;
}

void func_800935B0(unsigned char *object)
{
    unsigned char *anim;
    int active;
    unsigned char *player;
    int index;
    int state;

    state = object[30123];
    if (state >= 5 || (state < 2 && state != 0)) {
        return;
    }
    player = *(unsigned char **)(object + 22988);
    active = IsPlayerActive(player);
    if (!active || object[30123] == 2) {
        return;
    }
    anim = object + 24188;
    func_800971EC(anim, *(void **)(object + 22988), 0.58f,
                  *(unsigned char **)(object + 22988) + 4276, -1, -1);
    func_80096860(anim, 5, *(int *)(*(unsigned char **)(object + 22988) + 420), 0);
    index = (signed char)object[30120];
    func_80096C8C(anim, 5, D_800FC270->scores[index].value,
                  *(unsigned char **)(object + 30200) + index * 12,
                  *(short *)(*(unsigned char **)(object + 30204) + index * 28 + 2), 0);
    if (object[30123] == 4
        || (D_800FC270->mode == 4 && D_800FC270->subMode == 1)) {
        func_80096F54(anim, 5, D_800FC270->sound);
    }
}
