extern char *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *channel, int sound, int arg2, int arg3);

static inline void event_play_sound(char *self, int sound)
{
    unsigned char phase = *(unsigned char *)(self + 24041);

    if (phase != 4 && phase != 2 && phase != 3) {
        func_800C0110(D_800F3BC0, sound, 0, 0);
    }
}

void func_800A0088(char *self)
{
    int pending;
    int mode;
    int other;
    int sound;

    if (*(unsigned char *)(self + 24041) == 4) {
        return;
    }
    pending = *(int *)(self + 24104);
    if (pending != 1) {
        return;
    }
    mode = *(int *)(D_800FC270 + 2560);
    sound = -1;
    if (mode == 5) {
        sound = 24;
    } else {
        other = *(int *)(D_800FC270 + 2564);
        if (other == pending) {
            if (mode == 0) {
                sound = 171;
            } else if (mode == other) {
                sound = 173;
            } else if (mode == 2) {
                sound = 176;
            } else {
                sound = -1;
            }
        } else if (other == 5) {
            event_play_sound(self, 530);
            event_play_sound(self, 105);
            sound = 554;
        }
    }
    if (sound != -1) {
        event_play_sound(self, sound);
    }
    *(int *)(self + 24104) = 0;
}
