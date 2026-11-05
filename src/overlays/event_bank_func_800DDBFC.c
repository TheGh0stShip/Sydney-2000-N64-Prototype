typedef struct State {
    char pad0[1551];
    unsigned char mode;
    unsigned char done;
    char pad1[4];
    unsigned char kind;
    char pad2[12884 - 1558];
    char sub[25276 - 12884];
    int timeStart;
    int timeNow;
    int pad3;
    int timeEnd;
} State;

extern char D_80077A44[];
extern char D_800F1AE0[];
extern unsigned char D_80077BA0;
extern char D_800F26E0[];
extern int D_800F2744;
extern int D_800778BC;

extern void func_800D33A0(void *p, void *q, int a, int b);
extern int func_8001D4B8(void *p, int a, int b, int c);
extern void func_8001D640(void *p, int handle, int volume);
extern void func_800AC25C(void *p, int a, int b, int c);
extern int func_80017D54(void);
extern void func_800AB2A4(void *p, int a, int b, int c, int d, int e);

static inline int scale_volume(int volume, int scale)
{
    return (volume * scale) >> 15;
}

void func_800DDBFC(State *state)
{
    int handle;
    int now;

    if (state->done != 0) {
        return;
    }
    if (state->kind != 5) {
        func_800D33A0(state->sub, D_80077A44, 0, -1);
    }
    handle = func_8001D4B8(D_800F1AE0, 227, 0, 1);
    func_8001D640(D_800F1AE0, handle, scale_volume(*(int *)(D_800F1AE0 + 104), 32767));
    now = state->timeNow;
    state->timeStart = now;
    state->timeEnd = now + 11520;
    state->done = D_80077BA0;
    state->mode = 11;
    func_800AC25C(state, 92, 14, 0);
    if (func_80017D54() != 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 14, D_800778BC, 0, 0);
    }
}
