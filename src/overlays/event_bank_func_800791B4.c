typedef struct GameState {
    char pad0[0xA00];
    int level;
    char pad1[0xA0C - 0xA04];
    unsigned char limit;
    char pad2[0xD52 - 0xA0D];
    unsigned char flags;
} GameState;

extern GameState *D_800FC270;

int func_800791B4(char *self)
{
    self += 0x10000;
    self[0xB04]++;
    if (self[0xB04] >= D_800FC270->limit) {
        if (D_800FC270->level != 5 || (D_800FC270->flags & 4)) {
            return 0;
        }
        self[0xB04] = 0;
        return 1;
    }
    return 2;
}
