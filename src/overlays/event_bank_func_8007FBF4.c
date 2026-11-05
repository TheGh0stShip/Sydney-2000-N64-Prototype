typedef struct SlotEntry {
    signed char kind;
    unsigned char sub;
    unsigned char pad[6];
    signed char used;
    unsigned char pad2[3];
} SlotEntry;

extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *ctx, int id, int x, int y);

void func_8007FBF4(unsigned char *object)
{
    int id = -1;
    int extra = -1;
    unsigned int i = 0;
    unsigned char *base = D_800FC270;
    SlotEntry *slots = (SlotEntry *)(base + 2576);
    unsigned char *cur;
    int mode;

    for (i = 0; i < ((unsigned char *)D_800FC270)[2572]; i++) {
        if (slots[i].used == 0) {
            break;
        }
    }
    cur = D_800FC270;
    if (i != cur[2572]) {
        int kind = slots[i].kind;
        int v;
        if (kind != 8) {
            unsigned char *team = cur + kind * 60;
            v = team[32];
        } else {
            v = 3;
        }
        if (v == 3) {
            id = 295;
            extra = slots[i].sub;
        }
    }
    if (id != -1) {
        id += extra;
        if ((unsigned char)(object[0x8000 + 3229] - 3) >= 2) {
            func_800C0110(D_800F3BC0, id, 7680, 23040);
        }
        return;
    }
    mode = *(int *)(D_800FC270 + 2560);
    switch (mode) {
    case 0:
        if ((unsigned char)(object[0x8000 + 3229] - 3) >= 2) {
            func_800C0110(D_800F3BC0, 361, 7680, 23040);
        }
        break;
    case 1:
        if ((unsigned char)(object[0x8000 + 3229] - 3) >= 2) {
            func_800C0110(D_800F3BC0, 363, 7680, 23040);
        }
        break;
    case 2:
        if ((unsigned char)(object[0x8000 + 3229] - 3) >= 2) {
            func_800C0110(D_800F3BC0, 365, 7680, 23040);
        }
        break;
    }
}
