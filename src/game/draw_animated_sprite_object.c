#ifndef LEAF_NAME
#define LEAF_NAME drawAnimatedSpriteObject
#endif
#ifndef SCISSOR_NAME
#define SCISSOR_NAME setSpriteScissor
#endif
#ifndef GET_TIME_NAME
#define GET_TIME_NAME getTime
#endif
#ifndef DRAW_NAME
#define DRAW_NAME drawSprite
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct {
    u8 padding00[0x10];
} SpriteBitmap;

typedef struct {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    float scaleX;
    float scaleY;
    s16 expandX;
    s16 expandY;
    u16 attributes;
    s16 depth;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    s16 tlutStart;
    s16 tlutCount;
    void *lut;
    s16 imageStart;
    s16 imageStep;
    s16 bitmapCount;
    s16 displayListCount;
    s16 bitmapHeight;
    s16 bitmapRealHeight;
    u8 bitmapFormat;
    u8 bitmapSize;
    SpriteBitmap *bitmap;
} Sprite;

typedef struct {
    u8 padding00[2];
    u16 bitmapCount;
    u8 padding04[8];
    int columns;
    int rows;
    u8 padding14[2];
    u16 attributes;
    u8 padding18[4];
    int depth;
    float scaleX;
    float scaleY;
    u16 tileWidth;
    u16 tileHeight;
    u8 lastFrame;
    u8 frame;
    u8 frameStride;
    u8 padding2F[0xD];
    int format;
    u8 padding40;
    u8 red;
    u8 padding42;
    u8 green;
    u8 padding44;
    u8 blue;
    u8 padding46;
    u8 alpha;
    u8 padding48[4];
    SpriteBitmap *bitmaps;
    u8 padding50[4];
    void *lut;
    u8 padding58[0x28];
    u32 flags;
} SpriteObject;

extern u32 spriteOverlayEnabled __asm__("D_800620D8");
extern u64 spriteFrameTime __asm__("D_800620E0");
extern u32 spriteFrameInterval __asm__("D_800620E8");
extern Sprite spriteState __asm__("D_800620EC");
extern int screenWidth __asm__("D_8005A824");
extern int screenHeight __asm__("D_8005A828");
extern int screenMode __asm__("D_8005A83C");
extern u32 animationPaused __asm__("D_80047818");
extern DisplayCommand *displayListHead __asm__("D_800663DC");
extern const float spriteDefaultScale __asm__("D_80000EF8");
extern const float spriteHalfScale __asm__("D_80000EFC");
extern const float spriteMinimumScaleX __asm__("D_80000F00");
extern const float spriteMinimumScaleY __asm__("D_80000F04");

extern void SCISSOR_NAME(int, int, int, int);
extern u64 GET_TIME_NAME(void);
extern void DRAW_NAME(Sprite *, int, int);

void LEAF_NAME(SpriteObject *object, int x, int y)
{
    u32 flags = object->flags;
    DisplayCommand *command;

    if (!(flags & 4)) {
        return;
    }
    if ((flags & 0x10) && spriteOverlayEnabled == 0) {
        return;
    }
    if (flags & 0x80) {
        object->scaleX = spriteDefaultScale;
        object->scaleY = spriteDefaultScale;
    }
    SCISSOR_NAME(0, screenWidth - 1, 0, screenHeight - 1);

    if (object->format == 8) {
        spriteState.bitmapFormat = 2;
        spriteState.bitmapSize = 1;
        spriteState.lut = object->lut;
    } else {
        spriteState.bitmapFormat = 0;
        spriteState.bitmapSize = 2;
    }

    if (screenMode == 1) {
        spriteState.scaleX = object->scaleX * spriteHalfScale;
        spriteState.scaleY = object->scaleY;
        x /= 2;
    } else if (screenMode == 3) {
        spriteState.scaleX = object->scaleX;
        spriteState.scaleY = object->scaleY;
    } else if (screenMode == 2) {
        spriteState.scaleX = object->scaleX;
        spriteState.scaleY = object->scaleY + object->scaleY;
        y <<= 1;
    }

    if (spriteState.scaleX <= 0.0f) {
        spriteState.scaleX = spriteMinimumScaleX;
    }
    if (spriteState.scaleY <= 0.0f) {
        spriteState.scaleY = spriteMinimumScaleY;
    }
    spriteState.x = x;
    spriteState.y = y;
    spriteState.width = object->columns * object->tileWidth;
    spriteState.height = object->rows * object->tileHeight;
    spriteState.bitmapHeight = object->tileHeight;
    spriteState.bitmapRealHeight = object->tileHeight;

    if (object->flags & 0x20) {
        if (animationPaused == 0) {
            u64 now = GET_TIME_NAME();

            if ((u32)((now - spriteFrameTime) >> 8) > spriteFrameInterval) {
                object->frame++;
                if (object->frame > object->lastFrame) {
                    object->frame = 0;
                }
                spriteFrameTime = now;
            }
        }
        spriteState.bitmap = object->bitmaps + object->frame * object->frameStride;
    } else {
        spriteState.bitmap = object->bitmaps;
    }

    spriteState.attributes = object->attributes | 0x10;
    spriteState.imageStart = 0;
    spriteState.depth = object->depth << 1;
    spriteState.bitmapCount = object->bitmapCount;
    spriteState.red = object->red;
    spriteState.green = object->green;
    spriteState.blue = object->blue;
    spriteState.alpha = object->alpha;

    command = displayListHead++;
    command->word0 = 0xE2001D00;
    command->word1 = 4;
    command = displayListHead++;
    command->word0 = 0xEE000000;
    command->word1 = 0x7FF00000;
    DRAW_NAME(&spriteState, 0, 0);
    command = displayListHead++;
    command->word0 = 0xE2001D00;
    command->word1 = 0;
}
