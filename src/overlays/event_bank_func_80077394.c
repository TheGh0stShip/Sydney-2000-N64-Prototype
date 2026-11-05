typedef struct GameState {
    char pad0[2560];
    int mode;
    int sound;
} GameState;

extern GameState *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int volume, int flags);

void func_80077394(char *self)
{
    GameState *gs = D_800FC270;
    int sound = gs->sound;
    int mode;
    int id;

    if (sound) {
        mode = gs->mode;
        id = -1;
        if (mode == 5) {
            if (!self[0x10B04]) {
                id = 0;
            }
        } else if (sound == 1) {
            if (mode == 0) {
                id = 216;
            } else if (mode == 1) {
                id = 219;
            } else if (mode == 2) {
                id = 222;
            }
        } else if (sound == 2) {
            id = 227;
        } else if (sound == 4) {
            id = 228;
        } else if (sound == 5) {
            id = 226;
        }
        if (id != -1 && D_800FC270->sound) {
            func_800C0110(D_800F3BC0, id, 0, 0);
        }
    }
}
