typedef struct {
    char pad0[0x612];
    unsigned char mode;
    unsigned char slot;
    char pad614;
    unsigned char state;
    char pad616[0x61A4 - 0x616];
    int base;
    int addr;
    float rate;
} EventObject;

extern int *D_800FC270;

void func_800DADFC(EventObject *o)
{
    float rate;
    int base;

    if (o->state < 2) {
        if (o->state == 1 || *(int *)((char *)D_800FC270 + 0xA00) != 4) {
            base = 0xF000;
            o->mode = 1;
        } else {
            base = 0x1C200;
            o->mode = 0;
        }
        rate = *(float *)0x80071400;
        o->base = base;
        o->rate = rate;
    } else {
        rate = *(float *)0x80071404;
        o->mode = 18;
        o->base = 0xF000;
        o->rate = rate;
    }
    o->addr = o->base;
    o->addr = o->addr + o->slot * 0x5A00 + 0x10E00;
}
