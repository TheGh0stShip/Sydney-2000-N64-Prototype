#ifndef LEAF_NAME
#define LEAF_NAME initializeColorPalette
#endif

#ifndef PALETTE_NAME
#define PALETTE_NAME colorPalette
#endif

typedef unsigned short u16;

extern u16 PALETTE_NAME[];

void LEAF_NAME(void)
{
    u16 index = 255;
    u16 red = 255;
    u16 green = 255;
    u16 blue = 255;
    u16 count = 127;

    do {
        PALETTE_NAME[index--] = 0xFFC0 | ((blue >> 2) & 0x3E) | 1;
        count--;
        blue--;
    } while (count != 0xFFFF);

    blue = 128;
    count = 63;
    do {
        PALETTE_NAME[index--] = ((red << 8) & 0xF800) |
                                ((green << 3) & 0x07C0) |
                                ((blue >> 2) & 0x003E) | 1;
        red -= 2;
        green -= 3;
        count--;
        blue -= 2;
    } while (count != 0xFFFF);

    red = 128;
    green = 64;
    count = 63;
    do {
        PALETTE_NAME[index--] = ((red << 8) & 0xF800) |
                                ((green << 3) & 0x07C0) | 1;
        red -= 2;
        count--;
        green--;
    } while (count != 0xFFFF);
}
