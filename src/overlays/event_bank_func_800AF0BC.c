typedef struct {
    char pad[0xA00];
    int mode;
    int soundEnabled;
} GameState;

typedef struct {
    char pad[424];
    unsigned char soundA;
    unsigned char soundB;
    unsigned char kind;
} Player;

typedef struct {
    char pad[11704];
    Player *player;
    char pad2[0x8000 + 286 - 11708];
    unsigned char state;
} Owner;

extern GameState *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_8009B670(Player *object);
extern void func_800C0110(void *bank, int sound, int a, int b);

void func_800AF0BC(Owner *self)
{
    int index;
    int base;
    int sound;

    func_8009B670(self->player);
    if (self->state < 2) {
        if (D_800FC270->mode == 5 && self->player->kind == 1) {
            index = 0;
            base = self->player->soundA;
        } else {
            index = 34;
            base = self->player->soundB;
        }
        sound = index + base;
        if (D_800FC270->soundEnabled) {
            func_800C0110(D_800F3BC0, sound, 0, 0);
        }
    }
}
