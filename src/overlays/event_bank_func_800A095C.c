extern char *D_800FC270;
extern char D_800F3BC0[];
extern int D_800757FC[];
extern void func_800C0110(void *channel, int sound, int arg2, int arg3);
extern void func_800D33A0(void *queue, void *message, int count, int timeout);

static inline void event_play_sound(char *self, int sound)
{
    unsigned char phase = *(unsigned char *)(self + 24041);

    if (phase != 4 && phase != 2 && phase != 3) {
        func_800C0110(D_800F3BC0, sound, 0, 0);
    }
}

void func_800A095C(char *self)
{
    unsigned char *player = *(unsigned char **)(self + 23712);
    unsigned char slot = player[425];
    unsigned short sound;

    if (player[426] != 3 && *(int *)(D_800FC270 + 2560) == 5) {
        sound = player[424];
    } else {
        sound = slot + 34;
    }
    event_play_sound(self, sound);
    D_800757FC[4] = slot + 149;
    func_800D33A0(self + 13020, D_800757FC, 0, -1);
}
