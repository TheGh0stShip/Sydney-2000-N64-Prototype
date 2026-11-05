typedef struct {
    short id;
    short kind;
    short count;
    char pad6[3];
    char active;
    char pad10[2];
} SlotSetup;

extern int D_800F271C;
extern unsigned char D_800F4100[];
typedef struct {
    char pad0[500];
    signed char slotState[8];
    char pad508[3440 - 508];
    SlotSetup setups[8];
} SlotTable;

extern SlotTable *D_800FC270;

void func_800C6CCC(void)
{
    unsigned int i;
    SlotSetup *setup;

    if (D_800F271C == 7) {
        for (i = 0; i < 8; i++) {
            D_800F4100[i] = 1;
            D_800FC270->slotState[i] = 13;
            setup = &D_800FC270->setups[i];
            setup->id = i + 5;
            setup->kind = 29;
            setup->count = 3;
            setup->active = 1;
        }
    } else {
        for (i = 0; i < 8; i++) {
            D_800FC270->slotState[i] = -1;
        }
    }
}
