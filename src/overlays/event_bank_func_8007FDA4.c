typedef struct SlotEntry {
    signed char kind;
    unsigned char sub;
    unsigned char pad[6];
    signed char used;
    unsigned char pad2[3];
} SlotEntry;

extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern signed char func_8009B73C(int arg);
extern void func_800C0110(void *ctx, int id, int x, int y);

#define CAN_PLAY(o) ((unsigned char)((o)[0x8000 + 3229] - 3) >= 2)

void func_8007FDA4(unsigned char *object)
{
    signed char rank = func_8009B73C(0);
    unsigned int i;

    switch (*(int *)(D_800FC270 + 2564)) {
    case 2:
        if (CAN_PLAY(object)) {
            func_800C0110(D_800F3BC0, 485, 7680, 23040);
        }
        if (rank >= 19) {
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 375, 23040, 76800);
            }
        } else {
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 382, 23040, 76800);
            }
        }
        break;
    case 4:
        if (CAN_PLAY(object)) {
            func_800C0110(D_800F3BC0, 486, 7680, 23040);
        }
        if (rank >= 13) {
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 376, 23040, 76800);
            }
        } else {
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 383, 23040, 76800);
            }
        }
        break;
    case 5: {
        unsigned char *base = D_800FC270;
        SlotEntry *slots = (SlotEntry *)(base + 2576);

        for (i = 0; i < ((unsigned char *)D_800FC270)[2572]; i++) {
            if (slots[i].used == 0) {
                break;
            }
        }
        if (i != D_800FC270[2572]) {
            int id = slots[i].sub + 417;
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, id, 7680, 23040);
            }
        }
        switch (rank) {
        case 0:
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 380, 23040, 76800);
            }
            break;
        case 1:
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 378, 23040, 76800);
            }
            break;
        case 2:
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 379, 23040, 76800);
            }
            break;
        case 3:
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 377, 23040, 76800);
            }
            break;
        default:
            if (CAN_PLAY(object)) {
                func_800C0110(D_800F3BC0, 366, 23040, 76800);
            }
            break;
        }
        break;
    }
    }
}
