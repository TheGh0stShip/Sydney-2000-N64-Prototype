typedef struct {
    char pad[0xA00];
    int mode;
    int soundEnabled;
} GameState;

typedef struct {
    char pad[0x8000 + 286];
    unsigned char state;
    char pad2[348 - 287];
    int played;
} Owner;

extern GameState *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *bank, int sound, int a, int b);

void func_800AEE30(Owner *self)
{
    int sound;

    if (self->state == 0 || self->state == 5 || self->state == 1) {
        sound = -1;
        if (self->state != 5) {
            if (D_800FC270->mode == 4) {
                sound = 464;
            } else {
                sound = 471;
            }
        } else {
            sound = 471;
        }
        if (sound >= 0 && D_800FC270->soundEnabled) {
            func_800C0110(D_800F3BC0, sound, 0, 0);
        }
        self->played = 1;
    }
}
