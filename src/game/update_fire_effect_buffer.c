#ifndef LEAF_NAME
#define LEAF_NAME updateFireEffectBuffer
#endif
#ifndef STATE_NAME
#define STATE_NAME isRuntimePaused
#endif
#ifndef RANDOM_NAME
#define RANDOM_NAME randomNext
#endif

typedef unsigned int u32;
typedef unsigned short u16;

/* 32x32 heat field (plus one spill row) mapped through a palette into pixels. */
#define FIRE_WIDTH 32
#define FIRE_HEIGHT 32

typedef struct {
    u32 words[FIRE_WIDTH * FIRE_HEIGHT / 2];
} FirePixels;

extern u16 fireHeat[] __asm__("D_80063F38");
extern u16 fireImage[] __asm__("D_80064740");
extern u16 firePalette[] __asm__("D_80063D30");

extern int STATE_NAME(void);
extern int RANDOM_NAME(void);

void LEAF_NAME(void)
{
    u16 copy[FIRE_HEIGHT + 1][FIRE_WIDTH];
    u32 i;
    u32 j;
    u32 k;
    u32 x;
    u16 *pixels;
    u16 *image;
    u16 pixel;
    u16 darkLimit;

    if (STATE_NAME() != 0) {
        return;
    }

    /* Seed random hot spots inside the heat buffer. */
    for (i = 0; i < (u32)(RANDOM_NAME() % 300 + 100); i++) {
        x = RANDOM_NAME() % 31 + 1;
        fireHeat[((RANDOM_NAME() % 31 + 1) << 5) + x] = 0xF0;
    }

    /* Diffuse the heat and map it through the palette. */
    for (k = 0; k < 2; k++) {
        for (i = 0; i < 0x400; i++) {
            fireHeat[i] = ((u16)(fireHeat[i] + fireHeat[i + 33] + fireHeat[i + 31] +
                                 fireHeat[i + 32]) >> 2) & 0xFE;
            fireImage[i] = firePalette[fireHeat[i]];
        }
    }

    /* Transpose the image, dropping dark pixels. */
    *(FirePixels *)copy = *(FirePixels *)fireImage;
    k = 0;
    i = k;
    image = fireImage;
    pixels = &copy[0][0];
    darkLimit = 0x318D;
    for (; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            pixel = pixels[k++];
            image[j * 32 + i] = pixel;
            if (pixel < darkLimit) {
                image[j * 32 + i] = 0;
            }
        }
    }
}
