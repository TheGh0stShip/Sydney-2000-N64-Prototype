typedef struct {
    int a;
    int b;
    short c;
    short d;
    short e;
    short f;
} EventSlot;

void func_800E20D4(char *object)
{
    EventSlot *slot = (EventSlot *)(object + 25088);
    unsigned char i = 8;

    do {
        slot->a = -7680;
        slot->b = -7680;
        slot->c = 0;
        slot->d = 0;
        slot->e = 0;
        slot++;
        i--;
    } while (i);
}
