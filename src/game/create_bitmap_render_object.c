#ifndef LEAF_NAME
#define LEAF_NAME createBitmapRenderObject
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
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeBitmapObject
#endif

typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct BitmapRenderObject BitmapRenderObject;
struct BitmapRenderObject {
    u32 field00;
    u32 width;
    u32 height;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 signature;
    float scaleX;
    float scaleY;
    u16 field28;
    u16 field2A;
    u8 field2C;
    u8 field2D;
    u8 field2E;
    u8 padding2F;
    u32 field30;
    u32 padding34;
    BitmapRenderObject *child;
    u32 padding3C;
    u16 color0;
    u16 color1;
    u16 color2;
    u16 color3;
    void *firstHandle;
    void *secondHandle;
    void *thirdHandle;
    void *fourthHandle;
    float values[8];
    u32 padding78[2];
    u32 flags;
};

extern void *memoryContext __asm__("D_800F2758");
extern u32 objectCleanupBlocked __asm__("D_800620DC");
extern char bitmapObjectTag[] __asm__("D_80000F0C");
extern float bitmapDefaultScale __asm__("D_80000F5C");
extern float bitmapFallbackX __asm__("D_80000F60");
extern float bitmapFallbackY __asm__("D_80000F64");

extern void RELEASE_NAME(void *context, void **handle);
extern void CLEANUP_NAME(BitmapRenderObject *object);
extern void RELEASE_OBJECT_NAME(BitmapRenderObject *object);
extern s32 ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);
extern void INITIALIZE_NAME(BitmapRenderObject *object);

s32 LEAF_NAME(BitmapRenderObject **output)
{
    BitmapRenderObject *object = *output;
    s32 result;

    s32 i;

    if (object != 0 && (object->flags & 4) != 0 && objectCleanupBlocked == 0) {
        if (object->thirdHandle != 0) RELEASE_NAME(memoryContext, &object->thirdHandle);
        if (object->firstHandle != 0) RELEASE_NAME(memoryContext, &object->firstHandle);
        if (object->secondHandle != 0) RELEASE_NAME(memoryContext, &object->secondHandle);
        if (object->fourthHandle != 0) RELEASE_NAME(memoryContext, &object->fourthHandle);
        if (object->child != 0) {
            CLEANUP_NAME(object->child);
            object = object->child;
            if (object != 0) {
                CLEANUP_NAME(object);
                RELEASE_OBJECT_NAME(object);
            }
        }
    }

    result = ALLOCATE_NAME(memoryContext, (void **)output, 132, bitmapObjectTag);
    if (result != 0) {
        *output = 0;
        return -999;
    }

    object = *output;
    object->color0 = object->color1 = object->color2 = object->color3 = 255;
    object->scaleX = object->scaleY = bitmapDefaultScale;
    object->field00 = object->width = object->height = object->field0C = 0;
    object->field10 = object->field14 = object->field18 = 0;
    object->field28 = object->field2A = 0;
    object->firstHandle = object->secondHandle = object->thirdHandle = 0;
    object->signature = 0x1234;
    object->field30 = 0;
    object->child = 0;
    object->field2C = object->field2D = object->field2E = 0;
    object->flags = 0;
    INITIALIZE_NAME(object);
    object->scaleX = bitmapDefaultScale;
    object->color0 = object->color1 = object->color2 = object->color3 = 255;
    object->width = object->height = 100;
    if (object->scaleX <= 0.0f) object->scaleX = bitmapFallbackX;
    if (object->scaleY <= 0.0f) object->scaleY = bitmapFallbackY;
    for (i = 0; i < 8; i++) object->values[i] = 0.0f;
    return 0;
}
