typedef struct EventState {
    char pad0[2560];
    int phase;
    int soundEnabled;
} EventState;

typedef struct EventRace {
    char pad0[424];
    unsigned char winSound;
    unsigned char loseSound;
    unsigned char state;
} EventRace;

extern EventState *D_800FC270;
extern char D_800F3BC0[];
extern void func_8009B670(EventRace *race);
extern void func_800C0110(void *bank, int id, int a, int b);

void func_80094264(unsigned char *object)
{
    int won;
    int base;
    int index;
    int id;

    func_8009B670(*(EventRace **)(object + 22988));
    if (object[30123] < 2) {
        won = 0;
        if (D_800FC270->phase == 5) {
            unsigned char s = (*(EventRace **)(object + 22988))->state;
            if (s == 1) {
                won = 1;
            } else if (s == 2) {
                won = 1;
            }
        }
        if (won) {
            base = 0;
            index = (*(EventRace **)(object + 22988))->winSound;
        } else {
            base = 33;
            index = (*(EventRace **)(object + 22988))->loseSound;
        }
        id = base + index;
        if (D_800FC270->soundEnabled) {
            func_800C0110(D_800F3BC0, id, 0, 0);
        }
    }
}
