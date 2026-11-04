#ifndef LEAF_NAME
#define LEAF_NAME layoutSpriteObject
#endif
#ifndef FIRE_NAME
#define FIRE_NAME updateFireEffectBuffer
#endif
#ifndef DRAW_NAME
#define DRAW_NAME drawAnimatedSpriteObject
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 padding00[8];
    u16 *pixels;
    u8 padding0C[4];
} SpriteBitmap;

typedef struct SpriteObject SpriteObject;
struct SpriteObject {
    u8 padding00[4];
    int x;
    int y;
    u32 columns;
    u32 rows;
    u8 padding14[8];
    int depth;
    float scaleX;
    float scaleY;
    u16 tileWidth;
    u16 tileHeight;
    u8 padding2C[4];
    int depthOffset;
    float childScale;
    SpriteObject *child;
    u8 padding3C[0xC];
    u16 **pixelAddress;
    SpriteBitmap *bitmaps;
    u8 padding50[8];
    float left;
    float top;
    float right;
    float bottom;
    float cropLeft;
    float cropTop;
    float cropRight;
    float cropBottom;
    u8 padding78[8];
    u32 flags;
};

typedef struct {
    u8 padding00[0x54];
    float x;
    float y;
    u8 padding5C[0x6D];
    u8 layer;
} SpriteLayout;

extern u32 spriteOverlayEnabled __asm__("D_800620D8");
extern u16 fireImage[] __asm__("D_80064740");
extern const float childMinimumScaleX __asm__("D_80000FB0");
extern const float childMinimumScaleY __asm__("D_80000FB4");

extern void FIRE_NAME(void);
extern void DRAW_NAME(SpriteObject *object, int x, int y);

void LEAF_NAME(SpriteObject *object, SpriteLayout *layout)
{
    u32 flags;
    int depth;
    u16 columns;
    u16 rows;
    s16 cropLeft;
    s16 cropTop;
    s16 cropRight;
    s16 cropBottom;
    float originX;
    float originY;
    s16 xs[4];
    s16 ys[4];
    u8 texcoords[2][4];
    SpriteObject *child;

    if (layout == 0) {
        return;
    }
    flags = object->flags;
    if (!(flags & 2)) {
        return;
    }
    if (!(flags & 4)) {
        return;
    }
    if ((flags & 0x10) && spriteOverlayEnabled == 0) {
        return;
    }

    switch (layout->layer) {
    case 0: depth = 0x20; break;
    case 1: depth = 0x18; break;
    case 2: depth = 0x16; break;
    case 3: depth = 0x14; break;
    case 4: depth = 0x12; break;
    case 5: depth = 0x10; break;
    case 6: depth = 8; break;
    case 7: depth = 6; break;
    case 8: depth = 4; break;
    case 9: depth = 2; break;
    }
    object->depth = depth;
    object->depth += object->depthOffset;

    columns = object->columns;
    rows = object->rows;
    originX = layout->x;
    originY = layout->y;
    cropLeft = (u32)(columns * object->cropLeft);
    cropTop = (u32)(rows * object->cropTop);
    cropRight = (u32)(columns * object->cropRight);
    cropBottom = (u32)(rows * object->cropBottom);
    if (cropLeft < 0) {
        cropLeft = 0;
    }
    if (cropTop < 0) {
        cropTop = 0;
    }
    if (cropRight >= columns) {
        cropRight = columns - 1;
    }
    if (cropBottom >= rows) {
        cropBottom = rows - 1;
    }
    texcoords[0][0] = cropLeft + columns;
    texcoords[1][0] = cropTop + rows;
    texcoords[0][1] = cropRight + columns;
    texcoords[1][1] = cropTop + rows;
    texcoords[0][2] = cropLeft + columns;
    texcoords[1][2] = cropBottom + rows;
    texcoords[0][3] = cropRight + columns;
    texcoords[1][3] = cropBottom + rows;

    xs[0] = originX + object->left;
    ys[0] = originY + object->top;
    xs[1] = originX + object->right;
    ys[1] = originY + object->bottom;
    object->x = xs[0];
    object->y = ys[0];
    object->scaleX = (float)(xs[0] < xs[1] ? xs[1] - xs[0] : xs[0] - xs[1])
                   / (float)(object->columns * object->tileWidth);
    object->scaleY = (float)(ys[0] < ys[1] ? ys[1] - ys[0] : ys[0] - ys[1])
                   / (float)(object->rows * object->tileHeight);

    if ((object->flags & 0x10) && spriteOverlayEnabled != 0) {
        FIRE_NAME();
        *object->pixelAddress = fireImage;
        object->bitmaps->pixels = fireImage;
    }
    DRAW_NAME(object, object->x, object->y);

    child = object->child;
    if (child != 0) {
        child->scaleX = object->scaleX * object->tileWidth / object->childScale;
        child->scaleY = object->scaleY * object->tileHeight;
        if (child->scaleX <= 0.0f) {
            child->scaleX = childMinimumScaleX;
        }
        if (child->scaleY <= 0.0f) {
            child->scaleY = childMinimumScaleY;
        }
        DRAW_NAME(object->child, object->x, object->y);
    }
}
