typedef struct EventState {
    char pad0[2560];
    int phase;
    int soundEnabled;
} EventState;

extern EventState *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int a, int b);

void func_8008F018(unsigned char *object)
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
                    if (state->soundEnabled) {
                        func_800C0110(D_800F3BC0, 107, 0, 0);
                    }
                } else if (state->soundEnabled) {
                    func_800C0110(D_800F3BC0, 221, 0, 0);
                }
            }
        }
    }
}
