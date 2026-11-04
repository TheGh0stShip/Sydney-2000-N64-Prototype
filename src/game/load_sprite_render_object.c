#ifndef LEAF_NAME
#define LEAF_NAME loadSpriteRenderObject
#endif
#ifndef FORMAT_NAME
#define FORMAT_NAME formatString
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef CLEANUP_NAME
#define CLEANUP_NAME cleanupObjectResources
#endif
#ifndef RELEASE_OBJECT_NAME
#define RELEASE_OBJECT_NAME releaseObject
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureBitmapObject
#endif
#ifndef HALT_NAME
#define HALT_NAME setHaltState
#endif
#ifndef FIND_SUBSTRING_NAME
#define FIND_SUBSTRING_NAME findSubstring
#endif
#ifndef ATTACH_NAME
#define ATTACH_NAME createNestedRenderObject
#endif
#ifndef PALETTE_NAME
#define PALETTE_NAME initializeColorPalette
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct SpriteRenderObject SpriteRenderObject;
struct SpriteRenderObject {
    u32 words00[7];
    u32 marker;
    float firstScale;
    float secondScale;
    u16 padding28[2];
    u8 bytes2C[3];
    u8 padding2F;
    u32 value30;
    float nestedScale;
    SpriteRenderObject *child;
    u32 padding3C;
    u16 colors[4];
    void *firstHandle;
    void *secondHandle;
    void *thirdHandle;
    void *fourthHandle;
    float values58[8];
    u8 padding78[8];
    u32 flags;
};

extern u32 cleanupBlocked __asm__("D_800620DC");
extern u8 memoryContext[] __asm__("D_800F2758");
extern char spriteFormat[] __asm__("D_80000E80");
extern char spriteTag[] __asm__("D_80000F0C");
extern char powerBarWeightsName[] __asm__("D_80000F18");
extern char powerBarEightName[] __asm__("D_80000F28");
extern char powerBarName[] __asm__("D_80000F34");
extern char fireProcName[] __asm__("D_80000F40");
extern const float spriteInitialScale __asm__("D_80000F4C");
extern const float spriteDefaultScale __asm__("D_80000F50");
extern const float spriteMinimumFirstScale __asm__("D_80000F54");
extern const float spriteMinimumSecondScale __asm__("D_80000F58");

extern void FORMAT_NAME(char *output, char *format, char *value);
extern void RELEASE_NAME(void *context, void **handle);
extern void CLEANUP_NAME(SpriteRenderObject *object);
extern void RELEASE_OBJECT_NAME(SpriteRenderObject *object);
extern s32 ALLOCATE_NAME(void *context, void **handle, u32 size, char *tag);
extern s32 CONFIGURE_NAME(SpriteRenderObject *object, char *name, u32 first, u32 second);
extern void HALT_NAME(u32 state);
extern s32 FIND_SUBSTRING_NAME(char *text, char *pattern);
extern void ATTACH_NAME(SpriteRenderObject *object, u8 type);
extern void PALETTE_NAME(void);

s32 LEAF_NAME(SpriteRenderObject **objectAddress, char *name)
{
    SpriteRenderObject *object;
    SpriteRenderObject *child;
    float scale;
    char formattedName[512];

    FORMAT_NAME(formattedName, spriteFormat, name);

    /* Release the resources held by a previously loaded sprite object. */
    object = *objectAddress;
    if (object != 0 && (object->flags & 4) && cleanupBlocked == 0) {
        if (object->thirdHandle != 0) RELEASE_NAME(memoryContext, &object->thirdHandle);
        if (object->firstHandle != 0) RELEASE_NAME(memoryContext, &object->firstHandle);
        if (object->secondHandle != 0) RELEASE_NAME(memoryContext, &object->secondHandle);
        if (object->fourthHandle != 0) RELEASE_NAME(memoryContext, &object->fourthHandle);
        if (object->child != 0) {
            CLEANUP_NAME(object->child);
            child = object->child;
            if (child != 0) {
                CLEANUP_NAME(child);
                RELEASE_OBJECT_NAME(child);
            }
        }
    }

    if (ALLOCATE_NAME(memoryContext, (void **)objectAddress, sizeof(SpriteRenderObject), spriteTag) != 0) {
        *objectAddress = 0;
        return -999;
    }

    object = *objectAddress;
    object->colors[3] = 255;
    object->colors[2] = 255;
    object->colors[1] = 255;
    object->colors[0] = 255;
    object->firstScale = spriteInitialScale;
    object->secondScale = spriteInitialScale;
    object->words00[0] = 0;
    object->words00[1] = 0;
    object->words00[2] = 0;
    object->words00[3] = 0;
    object->words00[4] = 0;
    object->words00[5] = 0;
    object->words00[6] = 0;
    object->padding28[1] = 0;
    object->padding28[0] = 0;
    object->firstHandle = 0;
    object->secondHandle = 0;
    object->marker = 0x1234;
    object->value30 = 0;
    object->child = 0;
    object->thirdHandle = 0;
    object->bytes2C[0] = 0;
    object->bytes2C[1] = 0;
    object->bytes2C[2] = 0;
    object->flags = 0;

    /* A sprite that fails to load is fatal: halt forever. */
    if (CONFIGURE_NAME(object, formattedName, 0, 0) <= 0) {
        for (;;) {
            HALT_NAME(1);
            HALT_NAME(0);
        }
    }

    object->colors[0] = 255;
    object->colors[1] = 255;
    object->colors[2] = 255;
    object->colors[3] = 255;
    object->words00[1] = 100;
    object->words00[2] = 100;
    scale = spriteDefaultScale;
    object->firstScale = scale;
    object->secondScale = scale;
    if (scale <= 0.0f) object->firstScale = spriteMinimumFirstScale;
    if (object->secondScale <= 0.0f) object->secondScale = spriteMinimumSecondScale;
    object->values58[7] = 0.0f;
    object->values58[6] = 0.0f;
    object->values58[5] = 0.0f;
    object->values58[4] = 0.0f;
    object->values58[3] = 0.0f;
    object->values58[2] = 0.0f;
    object->values58[1] = 0.0f;
    object->values58[0] = 0.0f;

    /* Named power bar sprites carry a nested render object of a given type. */
    if (FIND_SUBSTRING_NAME(name, powerBarWeightsName) != 0) {
        ATTACH_NAME(object, 3);
        return 0;
    }
    if (FIND_SUBSTRING_NAME(name, powerBarEightName) != 0) {
        ATTACH_NAME(object, 1);
        return 0;
    }
    if (FIND_SUBSTRING_NAME(name, powerBarName) != 0) {
        ATTACH_NAME(object, 2);
        return 0;
    }
    if (FIND_SUBSTRING_NAME(name, fireProcName) != 0) {
        PALETTE_NAME();
        object->flags |= 0x10;
    }
    return 0;
}
