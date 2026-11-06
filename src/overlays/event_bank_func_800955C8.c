typedef struct Entry {
    char pad0[4];
    unsigned char state;
    char pad5[3];
    int a;
    int b;
    char pad10[4];
    int c;
    char pad18[4];
} Entry;

typedef struct Slot {
    char pad0[12];
} Slot;

typedef struct GameState {
    char pad0[0xA0C];
    unsigned char count;
    char padA0D[0xB];
    signed char flag[1];
} GameState;

extern GameState *D_800FC270;

#define SELF_TIME(s) (*(int *)((s) + 0x73F4))
#define SELF_IDX(s) (*(signed char *)((s) + 0x75A8))
#define SELF_MODE(s) (*(unsigned char *)((s) + 0x75AB))
#define SELF_ENT(s) (*(Entry **)((s) + 0x75FC))

int func_800955C8(char *s)
{
    unsigned int n = 0;
    unsigned int i;
    Entry *e;

    if ((unsigned char)(SELF_MODE(s) - 3) < 2) {
        return n;
    }
    for (i = 0; i < D_800FC270->count; i++) {
        e = &SELF_ENT(s)[i];
        if (e->state < 3) {
            n++;
        }
    }
    if (n == 1 && D_800FC270->flag[SELF_IDX(s) * 12] == 0) {
        return 1;
    }
    return 0;
}

int func_80095664(char *s)
{
    unsigned int i;
    unsigned int n;
    Entry *e;

    n = 0;
    for (i = 0; i < D_800FC270->count; i++) {
        e = &SELF_ENT(s)[i];
        if (e->state < 3) {
            int t = SELF_TIME(s);
            if (e->a < t && t != e->c) {
                n++;
            }
        }
    }
    return n == 0;
}

int func_800956CC(char *s)
{
    unsigned int i;
    unsigned int n;
    Entry *e;

    n = 0;
    for (i = 0; i < D_800FC270->count; i++) {
        e = &SELF_ENT(s)[i];
        if (e->state >= 3) {
            n++;
        }
    }
    return !(n < D_800FC270->count);
}

void func_80095718(char *s)
{
    SELF_ENT(s)[SELF_IDX(s)].c = SELF_TIME(s);
    SELF_ENT(s)[SELF_IDX(s)].b = SELF_TIME(s) + 3;
}
