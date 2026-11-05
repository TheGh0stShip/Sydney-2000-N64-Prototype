typedef struct EventState {
    char pad0[2560];
    int phase;
    int soundEnabled;
} EventState;

typedef struct EventRace {
    char pad0[748];
    int finishType;
} EventRace;

extern EventState *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int a, int b);

void func_8008E900(unsigned char *object)
{
    unsigned char mode = object[0x8000 + 1047];
    EventState *state;
    int phase;

    if (mode == 0 || mode == 5 || mode == 1) {
        state = D_800FC270;
        phase = state->phase;
        if (phase < 6) {
            if (phase >= 0) {
                if (object[0x8000 + 1047] == 5) {
                    switch ((*(EventRace **)(object + 23004))->finishType) {
                    case 0:
                        if (state->soundEnabled) {
                            func_800C0110(D_800F3BC0, 164, 0, 7680);
                        }
                        break;
                    case 2:
                        if (state->soundEnabled) {
                            func_800C0110(D_800F3BC0, 163, 0, 7680);
                        }
                        break;
                    }
                }
            }
        }
    }
}
