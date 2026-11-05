typedef struct {
    unsigned char data[192];
    int flags;
    unsigned char rest[16];
} Part;

void func_800CC390(unsigned char *object)
{
    unsigned char bits = object[1927] | 2;
    unsigned char i;
    int mask;

    object[1927] = bits;
    bits &= 0x21;
    if (bits == 1) {
        i = 0;
    } else if (bits == 32) {
        i = 2;
    } else {
        i = 3;
    }
    mask = ~4;
loop:
    if (i < 8) {
        ((Part *)(object + 216))[i].flags &= mask;
        i++;
        goto loop;
    }
    ((Part *)object)->flags &= ~4;
}
