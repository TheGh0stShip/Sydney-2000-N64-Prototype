#ifndef LEAF_NAME
#define LEAF_NAME resetBitmapRenderObject
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
#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureBitmapObject
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct BitmapRenderObject BitmapRenderObject;
struct BitmapRenderObject {
    u32 words00[7];
    u32 marker;
    float firstScale;
    float secondScale;
    u16 padding28[2];
    u8 bytes2C[3];
    u8 padding2F;
    u32 value30;
    u32 padding34;
    BitmapRenderObject *child;
    u32 padding3C;
    u16 colors[4];
    void *firstHandle;
    void *secondHandle;
    void *thirdHandle;
    void *fourthHandle;
    float values58[8];
    u8 padding78[8];
    u32 value80;
};

extern u32 cleanupBlocked __asm__("D_800620DC");
extern void *memoryContext __asm__("D_800F2758");
extern char bitmapFormat[] __asm__("D_80000E80");
extern float bitmapDefaultScale __asm__("D_80000F08");

extern void FORMAT_NAME(char *output, char *format, char *value);
extern void RELEASE_NAME(void *context, void **handle);
extern void CLEANUP_NAME(BitmapRenderObject *object);
extern void RELEASE_OBJECT_NAME(BitmapRenderObject *object);
extern void CONFIGURE_NAME(BitmapRenderObject *object, char *name, u32 first, u32 second);

s32 LEAF_NAME(BitmapRenderObject **objectAddress, char *name)
{
    BitmapRenderObject *object = *objectAddress;
    BitmapRenderObject *child;
    float savedValues[8];
    char formattedName[512];
    s32 result;
    u32 i;

    if (object == 0) {
        return 0;
    }

    FORMAT_NAME(formattedName, bitmapFormat, name);
    for (i = 0; i < 8; i++) {
        savedValues[i] = object->values58[i < 5 ? i : 4];
    }

    if (cleanupBlocked == 0) {
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

    object->colors[3] = 255;
    object->colors[2] = 255;
    object->colors[1] = 255;
    object->colors[0] = 255;
    for (i = 0; i < 7; i++) object->words00[i] = 0;
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
    object->value80 = 0;
    object->firstScale = bitmapDefaultScale;
    object->secondScale = bitmapDefaultScale;
    CONFIGURE_NAME(object, formattedName, 0, 0);
    for (i = 0; i < 8; i++) object->values58[i] = savedValues[i];
    return result;
}
