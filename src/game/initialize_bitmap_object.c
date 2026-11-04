#ifndef LEAF_NAME
#define LEAF_NAME initializeBitmapObject
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u16 width;
    u16 height;
    u16 x;
    u16 y;
    void *pixels;
    u16 stride;
    u16 reserved;
} BitmapRecord;

typedef struct {
    u32 count;
    u32 field04;
    u32 field08;
    u32 width;
    u32 height;
    u32 flags;
    u32 enabled;
    u32 padding1C;
    float scaleX;
    float scaleY;
    u16 stepX;
    u16 stepY;
    u8 padding2C[0x10];
    u32 capacity;
    u8 padding40[8];
    void **bitData;
    BitmapRecord *bitmaps;
    void *pixelBuffer;
    u32 field54;
    u8 padding58[0x28];
    u32 state;
} BitmapObject;

extern u8 memoryContext[];
extern char bitDataName[];
extern char bitmapsName[];
extern char pixelBufferName[];
extern float bitmapUnitScale;
extern void ALLOCATE_NAME(void *context, void **handle, u32 size, char *name);

u32 LEAF_NAME(BitmapObject *object)
{
    u32 bitDataSize;

    object->count = 1;
    object->field04 = 0;
    object->field08 = 0;
    object->width = 4;
    object->height = 4;
    object->flags = 1;
    object->enabled = 1;
    object->scaleX = bitmapUnitScale;
    object->scaleY = bitmapUnitScale;
    object->stepX = 1;
    object->stepY = 1;
    object->capacity = 16;
    object->pixelBuffer = 0;
    object->bitData = 0;
    object->pixelBuffer = 0;
    object->field54 = 0;

    bitDataSize = (object->flags + 1) * 4;
    object->flags |= 8;
    ALLOCATE_NAME(memoryContext, (void **)&object->bitData,
                  bitDataSize, bitDataName);
    ALLOCATE_NAME(memoryContext, (void **)&object->bitmaps,
                  (object->count + 1) * 16, bitmapsName);
    ALLOCATE_NAME(memoryContext, &object->pixelBuffer, 64, pixelBufferName);

    *object->bitData = object->pixelBuffer;
    object->bitmaps->width = 4;
    object->bitmaps->height = 4;
    object->bitmaps->x = 0;
    object->bitmaps->y = 0;
    object->bitmaps->pixels = *object->bitData;
    object->bitmaps->stride = 4;
    object->bitmaps->reserved = 0;
    object->state |= 6;
    return object->count;
}
