typedef struct Slot {
    signed char team;
    char pad1;
    short timer;
    float value;
    signed char link;
    char pad9;
    unsigned char flag;
    char padB;
} Slot;

typedef struct Team {
    char pad[0x20];
    unsigned char mode;
    char rest[27];
} Team;

typedef struct Fader {
    int current;
    int target;
    int pending;
} Fader;

extern unsigned char *D_800FC270;
extern Fader D_800445F0;
extern unsigned char D_800F2AD8[];
extern int D_800F2728;

extern void func_80017A90(int mask);
extern void func_800BC274(void *a);
extern int func_80017D54(void);
extern void func_800ED894(void *a);
extern void func_80008534(Fader *f);
extern void func_80008540(Fader *f);
extern void func_80074ECC(unsigned char *state);
extern void func_80074800(unsigned char *state, int a);
extern void func_800BC180(void *a);
extern void func_8007368C(unsigned char *state);
extern void func_8000C944(void);
extern void func_8009BB88(int a, int b);
extern void func_800177F8(void);

void func_8009EA04(unsigned char *state)
{
    Slot *slot;
    unsigned char next;
    Fader *fader;
    float init;
    Team *team;

    func_80017A90(0x40000000);
    func_800BC274(D_800F2AD8);
    if (func_80017D54() != 0) {
        func_800ED894(state + 0x5E74);
    }
    fader = &D_800445F0;
    if (fader->pending == 1) {
        D_800445F0.current = fader->target;
        if (fader->target != 0) {
            func_80008534(fader);
        } else {
            func_80008540(fader);
        }
        fader->pending = 0;
    }
    for (;;) {
        init = *(float *)0x80071168;
        slot = &((Slot *)(D_800FC270 + 0xA10))[state[0x5DE6]];
        slot->flag = 0;
        slot->link = -1;
        slot->value = init;
        slot->timer = 0;
        state[0x5E3A] = 0;
        state[0x5E3B] = 0;
        if (slot->team != 8) {
            team = &((Team *)D_800FC270)[slot->team];
            if (team->mode == 1) {
                state[0x5E3A]++;
            } else {
                state[0x5E3B] = 1;
            }
        }
        if (state[0x5E3A] != 0) {
            break;
        }
        func_80074ECC(state);
        func_80074800(state, 0);
        if (state[0x5DE9] == 1) {
            func_800BC180(D_800F2AD8);
            break;
        }
        next = state[0x5DE6];
        state[0x5DE6] = next + 1;
        if ((unsigned char)(next + 1) >= D_800FC270[0xA0C]) {
            state[0x5DE6] = next;
            *(int *)(state + 0x5E08) = 0;
            state[0x5DE7] = 20;
            *(int *)(state + 0xAC) = 1;
            return;
        }
    }
    func_8007368C(state);
    func_8000C944();
    state[0x5E3C] = 0;
    D_800F2728 = 0;
    *(int *)(state + 0x5E14) = -0x1E00;
    *(int *)(state + 0x5E04) = -0x1E00;
    *(int *)(state + 0x5E2C) = 0;
    *(int *)(state + 0x5E1C) = 0;
    state[0x5DE7] = 0;
    *(int *)(state + 0xAC) = 1;
    func_80017A90(0x20000000);
    func_8009BB88(state[0x5DE9], 1);
    func_800177F8();
}
