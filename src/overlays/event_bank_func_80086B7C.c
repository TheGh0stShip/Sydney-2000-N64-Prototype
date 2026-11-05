extern void func_800C0110(void *object, int id, int a, int b);
extern unsigned char *D_800FC270;
extern unsigned int D_800F2714;
extern unsigned char D_800F3BC0[];

typedef struct {
    int a;
    int pad0;
    int b;
    unsigned char pad1[10];
    short state;
    unsigned char pad2[12];
} Slot;

typedef struct {
    unsigned char pad0[1548];
    unsigned char current;
    unsigned char pad1[16672 - 1549];
    unsigned char *players[8];
    unsigned char pad2[21244 - 16704];
    Slot slots[9];
    unsigned char pad3[21568 - 21568];
    int soundEnabled;
} Game;

void func_80086B7C(Game *game)
{
    unsigned char index;
    int id;

    index = game->players[game->current][733];
    id = -1;
    if (game->slots[index].state == 1) {
        return;
    }
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    if ((D_800F2714 >> 28) >= 2) {
        if (game->slots[index].a < 11521) {
            id = 570;
        } else {
            id = 562;
        }
        id += index;
    }
    if (id != -1 && *(int *)(D_800FC270 + 2564) != 0 && game->soundEnabled == 1) {
        func_800C0110(D_800F3BC0, id, 0, 0);
    }
}
