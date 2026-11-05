typedef struct GameState {
    char pad0[2560];
    int level;
} GameState;

extern GameState *D_800FC270;
extern void *D_800766B4[];
extern void *D_80076690[];
extern void func_80013E7C(void *res, void *dst, int flags);

void func_800790E8(char *self, int enable)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (enable) {
            int level = D_800FC270->level;
            if (level >= 0) {
                if (level >= 3) {
                    if (level < 7) {
                        func_80013E7C(D_80076690[i], self + 0x10D70 + i * 4, 0);
                    }
                } else {
                    func_80013E7C(D_800766B4[i], self + 0x10D70 + i * 4, 0);
                }
            }
        }
    }
}
