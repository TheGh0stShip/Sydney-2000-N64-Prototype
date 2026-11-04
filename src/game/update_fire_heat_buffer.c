#ifndef LEAF_NAME
#define LEAF_NAME updateFireHeatBuffer
#endif
#ifndef PALETTE_SETUP_NAME
#define PALETTE_SETUP_NAME initializeColorPalette
#endif
#ifndef RANDOM_NAME
#define RANDOM_NAME randomNext
#endif
#ifndef HEAT_BUFFER_NAME
#define HEAT_BUFFER_NAME heatBuffer
#endif
#ifndef PIXEL_BUFFER_NAME
#define PIXEL_BUFFER_NAME pixelBuffer
#endif
#ifndef PALETTE_NAME
#define PALETTE_NAME colorPalette
#endif

typedef signed int s32;
typedef unsigned short u16;

/* 32x32 heat field (plus one spill row) mapped through a palette into pixels. */
#define FIRE_WIDTH 32
#define FIRE_HEIGHT 32
#define FIRE_BOTTOM_ROW ((FIRE_HEIGHT - 1) * FIRE_WIDTH)

extern u16 HEAT_BUFFER_NAME[];
extern u16 PIXEL_BUFFER_NAME[];
extern u16 PALETTE_NAME[];
extern void PALETTE_SETUP_NAME(void);
extern s32 RANDOM_NAME(void);

void LEAF_NAME(void)
{
    s32 i;
    s32 row;
    s32 count;
    u16 heat;

    PALETTE_SETUP_NAME();

    /* Seed the bottom row: roughly one in five cells flares to full heat. */
    for (i = 2; i < FIRE_WIDTH - 2; i++) {
        HEAT_BUFFER_NAME[FIRE_BOTTOM_ROW + i] = 0;
        if (RANDOM_NAME() % 10 >= 8) {
            HEAT_BUFFER_NAME[FIRE_BOTTOM_ROW + i] = 0xFF;
        }
    }

    /* Cool the edges, with a random depth for the inner columns. */
    for (row = 0; row < FIRE_HEIGHT; row++) {
        HEAT_BUFFER_NAME[row * FIRE_WIDTH] = 0;
        HEAT_BUFFER_NAME[row * FIRE_WIDTH + FIRE_WIDTH] = 0;
    }
    count = RANDOM_NAME() % 16;
    for (row = 0; row < count; row++) {
        HEAT_BUFFER_NAME[row * FIRE_WIDTH + 1] = 0;
        HEAT_BUFFER_NAME[row * FIRE_WIDTH + FIRE_WIDTH - 1] = 0;
    }
    count = RANDOM_NAME() % 8;
    for (row = 0; row < count; row++) {
        HEAT_BUFFER_NAME[row * FIRE_WIDTH + 2] = 0;
        HEAT_BUFFER_NAME[row * FIRE_WIDTH + FIRE_WIDTH - 2] = 0;
    }

    /* Propagate heat upward by averaging the cells below, then colorize. */
    for (i = 0; i < FIRE_WIDTH * FIRE_HEIGHT; i++) {
        heat = ((u16)(HEAT_BUFFER_NAME[i] + HEAT_BUFFER_NAME[i + FIRE_WIDTH + 1] +
                      HEAT_BUFFER_NAME[i + FIRE_WIDTH - 1] + HEAT_BUFFER_NAME[i + FIRE_WIDTH]) >> 2) & 0xFE;
        HEAT_BUFFER_NAME[i] = heat;
        if (heat < 10) {
            PIXEL_BUFFER_NAME[i] = 0;
        } else {
            PIXEL_BUFFER_NAME[i] = PALETTE_NAME[HEAT_BUFFER_NAME[i]];
        }
    }

    for (i = 0; i < FIRE_WIDTH; i++) {
        PIXEL_BUFFER_NAME[FIRE_BOTTOM_ROW + i] = 0;
    }
}
