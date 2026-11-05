extern void func_800C0110(void *object, int id, int a, int b);
extern unsigned char *D_800FC270;
extern unsigned int D_800F2714;
extern unsigned char D_800F3BC0[];

typedef struct {
    int a;
    int pad0;
    int b;
    int pad1;
    int c;
    unsigned char pad2[2];
    short state;
    unsigned char pad3[12];
} Slot;

typedef struct {
    unsigned char pad0[21244];
    Slot slots[9];
    int soundEnabled;
    unsigned char pad1[21615 - 21572];
    unsigned char current;
} Game;

void func_80086A58(Game *game)
{
    int id;

    if (game->slots[game->current].state == 1) {
        return;
    }
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    id = 595;
    if ((D_800F2714 >> 28) < 4) {
        id = 553;
    }
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    if ((D_800F2714 >> 28) >= 2) {
        if (game->slots[game->current].c < 4609) {
            id += 1;
        } else {
            id -= 8;
        }
        id += game->current;
    }
    if (id != -1 && *(int *)(D_800FC270 + 2564) != 0 && game->soundEnabled == 1) {
        func_800C0110(D_800F3BC0, id, 0, 0);
    }
}
