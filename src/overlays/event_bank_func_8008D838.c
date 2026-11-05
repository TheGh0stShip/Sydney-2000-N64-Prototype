extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern unsigned char func_8009B670(void *obj);
extern void func_800C0110(void *a, int b, int c, int d);

void func_8008D838(unsigned char *state)
{
    unsigned char level;
    unsigned char *obj;
    int sound;
    int variant;
    int mode;
    int id;

    level = func_8009B670(*(void **)(state + 0x59DC));
    if (state[0x8417] >= 2) {
        return;
    }
    if (*(int *)(D_800FC270 + 0xA00) == 5 &&
        (obj = *(unsigned char **)(state + 0x59DC))[0x1AA] != 3) {
        sound = 4;
        variant = obj[0x1A8];
    } else {
        sound = 0x26;
        variant = (*(unsigned char **)(state + 0x59DC))[0x1A9];
    }
    id = sound + variant;
    if (*(int *)(D_800FC270 + 0xA04) != 0) {
        func_800C0110(D_800F3BC0, id, 0, 0);
    }
    mode = *(int *)(D_800FC270 + 0xA00);
    sound = -1;
    if (mode != 4) {
        return;
    }
    if (*(int *)(D_800FC270 + 0xA04) == mode) {
        if ((signed char)state[0x8414] == 1) {
            sound = 0x211;
        } else if ((signed char)state[0x8414] == 2) {
            sound = 0x217;
        }
    } else if (*(int *)(D_800FC270 + 0xA04) == 5) {
        if ((signed char)state[0x8414] != 2) {
            sound = 0x21D;
        } else if ((*(unsigned char **)(state + 0x59DC))[0x1AA] == 1) {
            sound = 0x227;
        } else {
            sound = 0x222;
        }
    }
    if (level < 4) {
        variant = level;
    } else if (level < 8) {
        variant = 4;
    } else {
        variant = 5;
    }
    if (sound >= 0) {
        id = sound + variant;
        if (*(int *)(D_800FC270 + 0xA04) != 0) {
            func_800C0110(D_800F3BC0, id, 0, 0);
        }
    }
}
