#ifndef LEAF_NAME
#define LEAF_NAME convertImageTiles
#endif

#ifndef ENABLED_NAME
#define ENABLED_NAME imageConversionEnabled
#endif

#ifndef OUTPUT_NAME
#define OUTPUT_NAME imageTileOutput
#endif

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 ENABLED_NAME;
extern u16 OUTPUT_NAME[];

void LEAF_NAME(u16 *source, u32 width)
{
    u32 columnStep;
    u32 rowStep;
    u32 sourceColumn;
    u32 sourceRow;
    u32 tile;
    u32 pixel;
    u32 bank;
    u32 row;
    u16 *input;
    u16 *first;
    u16 *second;

    if (ENABLED_NAME == 0) {
        return;
    }

    sourceColumn = 16;
    columnStep = 4;
    sourceRow = width * 3;
    if (width == 640) {
        sourceColumn = 24;
        columnStep = 9;
        sourceRow = 1920;
    }
    rowStep = sourceRow * 2;
    input = source + sourceColumn + (32 * width);

    for (tile = 0; tile < 64; tile++) {
        if (tile < 32) {
            row = tile;
            bank = 0;
        } else {
            row = tile - 32;
            bank = 2;
        }
        first = OUTPUT_NAME + (bank << 10) + (row << 5) + 31;
        second = OUTPUT_NAME + 1024 + (bank << 10) + (row << 5) + 31;
        input = source + sourceColumn + (32 * width) + (tile * rowStep);
        for (pixel = 0; pixel < 32; pixel++) {
            *first-- = *input | 1;
            input += columnStep;
        }
        for (; pixel < 64; pixel++) {
            *second-- = *input | 1;
            input += columnStep;
        }
    }
}
