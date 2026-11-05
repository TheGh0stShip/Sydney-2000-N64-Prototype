typedef struct Group {
    unsigned short count;
    signed char members[8];
} Group;

typedef struct Racer {
    unsigned char status;
    char pad0[43];
    signed char group;
    char pad1[15];
} Racer;

typedef struct RaceState {
    char pad0[32];
    Racer racers[8];
} RaceState;

extern Group D_801032F0[30];
extern unsigned char D_80103420[8];
extern unsigned char D_80103428;
extern RaceState *D_800FC270;

void func_800D9F0C(void)
{
    Group *g;
    unsigned char i;
    unsigned char j;

    g = D_801032F0;
    i = 30;
    do {
        g->count = 0;
        for (j = 0; j < 8; j++) {
            g->members[j] = -1;
        }
        g++;
        i--;
    } while (i);

    i = 0;
    while (1) {
        if (i >= 8) {
            break;
        }
        switch (D_800FC270->racers[i].status) {
        case 0:
            break;
        case 1:
        case 2:
            g = &D_801032F0[D_800FC270->racers[i].group];
            g->members[g->count] = i;
            g->count++;
            break;
        case 3:
            break;
        case 4:
            break;
        }
        i++;
    }

    D_80103428 = 0;
    for (i = 8; i != 0; i--) {
        for (j = 0; j < 29; j++) {
            if (D_801032F0[j].count == i) {
                D_80103420[D_80103428] = j;
                D_80103428++;
            }
        }
    }
}
