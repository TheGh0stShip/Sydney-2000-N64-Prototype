typedef struct EventState {
    char pad0[2560];
    int phase;
    int soundEnabled;
} EventState;

typedef struct EventRace {
    char pad0[768];
    int falseStart;
    int disqualified;
} EventRace;

extern EventState *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int a, int b);

void func_8008E9C4(unsigned char *object)
{
    unsigned char mode = object[0x8000 + 1047];
    EventState *state;
    EventRace *race;

    if (mode == 0 || mode == 5 || mode == 1) {
        state = D_800FC270;
        if (state->phase == 4) {
            race = *(EventRace **)(object + 23004);
            if (race->falseStart) {
                if (state->soundEnabled) {
                    func_800C0110(D_800F3BC0, 122, 0, 0);
                }
                return;
            }
            if (race->disqualified) {
                if (state->soundEnabled) {
                    func_800C0110(D_800F3BC0, 343, 0, 0);
                }
                return;
            }
        }
        if (state->soundEnabled) {
            func_800C0110(D_800F3BC0, 111, 0, 0);
        }
    }
}
