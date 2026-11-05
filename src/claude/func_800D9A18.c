typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct Slot {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
    u8 mode;
    char pad9[3];
} Slot;
typedef char assert_slot_size[(sizeof(Slot) == 0xC) ? 1 : -1];

typedef struct Save {
    char pad0[0x4F0];
    s16 unk4F0;
    char pad4F2[0xD70 - 0x4F2];
    Slot slots[9];
} Save;

extern Save *D_800FC270;
extern u32 runtimeSystemReady;
extern u8 runtimeCurrentMode;

void func_800D9A18(void)
{
    u8 i;
    Slot *s;
    Save *p = D_800FC270;

    s = p->slots;
    for (i = 0; i < 8; s++, i++) {
        switch (runtimeSystemReady) {
        case 0:
        case 1:
        case 6:
        case 7:
            s->x = i + 5;
            s->y = 0x1D;
            s->z = 3;
            break;
        case 2:
        case 4:
            s->x = 0xE;
            s->y = 0x21;
            s->z = i + 5;
            break;
        case 3:
            s->x = 0x20;
            s->y = 0x1D;
            s->z = i + 5;
            break;
        case 5:
            s->x = 0x17;
            s->y = 0x22;
            s->z = i + 5;
            break;
        }
        if (i == 0) {
            s->mode = runtimeCurrentMode;
        }
    }
    s = &D_800FC270->slots[8];
    s->x = 0xE;
    s->mode = runtimeCurrentMode;
    s->y = 0xE;
    s->z = 0xE;
    s->w = 0;
    D_800FC270->unk4F0 = runtimeCurrentMode;
}
