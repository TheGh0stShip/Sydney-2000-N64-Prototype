#ifndef LEAF_NAME
#define LEAF_NAME fillBitmapObject
#endif

#ifndef FILL_NAME
#define FILL_NAME fillBytes
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 count;
    u8 padding04[8];
    u32 width;
    u32 height;
    u32 flags;
    u8 padding18[0x24];
    u32 capacity;
    u16 red;
    u16 green;
    u16 blue;
    u16 alpha;
    void **bitData;
    u8 padding4C[8];
    u16 *pixelBuffer;
    u8 padding58[0x28];
    u32 state;
} BitmapObject;

extern void FILL_NAME(void *destination, u32 value, u32 size);

u32 LEAF_NAME(BitmapObject **objectAddress, u32 color)
{
    BitmapObject *object = *objectAddress;
    u32 index;
    u32 packed;
    u32 size;

    if (object == 0) {
        return 0;
    }

    object->red = (color >> 16) & 0xFF;
    object->green = (color >> 8) & 0xFF;
    object->blue = color & 0xFF;
    object->alpha = color >> 24;
    if ((object->state & 8) == 0) {
        return 0;
    }

    packed = ((color >> 8) & 0xF800) |
             ((color >> 5) & 0x07C0) |
             ((color >> 2) & 0x003E) | 1;
    object->flags = 9;
    size = object->width * object->height * 2;

    if (object->capacity == 8) {
        for (index = 0; index < object->count; index++) {
            FILL_NAME(object->bitData[index], 0, size);
            *object->pixelBuffer = packed;
        }
    } else {
        for (index = 0; index < object->count; index++) {
            FILL_NAME(object->bitData[index], packed & 0xFFFF, size);
        }
    }
    return 0;
}
