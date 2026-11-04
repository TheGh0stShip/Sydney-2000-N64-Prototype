#ifndef LEAF_NAME
#define LEAF_NAME applyPackedColorUpdate
#endif
#ifndef TRANSFORM_NAME
#define TRANSFORM_NAME transformColorVector
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 flags;
    u8 red;
    u8 green;
    u8 blue;
    s32 mode;
    u8 padding08[0xC];
    u8 transform[0x14];
    u32 mask;
} ColorUpdate;

extern u8 displayState[] __asm__("D_80043D48");
extern double colorVectorScale __asm__("D_80000558");
extern void TRANSFORM_NAME(void *source, float output[3]);

s32 LEAF_NAME(ColorUpdate *update)
{
    u32 type;
    u32 index;
    float vector[3];

    if ((update->flags & 0x40) == 0) {
        if (update->mode != 2) {
            return -992;
        }
    } else if (update->mode != -992) {
        TRANSFORM_NAME(update->transform, vector);
        vector[0] = (float)((double)vector[0] * colorVectorScale);
        vector[1] = (float)((double)vector[1] * colorVectorScale);
        vector[2] = (float)((double)vector[2] * colorVectorScale);

        type = update->flags & 0xBF;
        for (index = 0; index < *(u32 *)(displayState + 0x48 + type * 4);
             index++) {
            u8 *entry = *(u8 **)(displayState + 0x88 + type * 4) + index * 32;
            entry[8] = update->red;
            entry[9] = update->green;
            entry[10] = update->blue;
            entry[12] = update->red;
            entry[13] = update->green;
            entry[14] = update->blue;
            entry[16] = (s32)vector[0];
            entry[17] = (s32)vector[1];
            entry[18] = (s32)vector[2];
        }
        return 0;
    }

    for (index = 0; index < 3; index++) {
        if (update->mask & (1U << index)) {
            *(u32 *)(displayState + 8 + index * 4) =
                0xFF000000 | ((u32)update->red << 16) |
                ((u32)update->green << 8) | update->blue;
        }
    }
    return 0;
}
