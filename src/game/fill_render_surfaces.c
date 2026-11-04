#ifndef LEAF_NAME
#define LEAF_NAME fillRenderSurfaces
#endif

#ifndef FILL_NAME
#define FILL_NAME fillMemory
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RenderSurfaceSet {
    u32 count;
    u8 pad0004[0x08];
    u32 width;
    u32 height;
    u32 state;
    u8 pad0018[0x24];
    u32 type;
    u16 red;
    u16 green;
    u16 blue;
    u16 alpha;
    void **surfaces;
    u8 pad004C[0x08];
    u16 *firstPixel;
    u8 pad0058[0x28];
    u32 flags;
} RenderSurfaceSet;

extern void FILL_NAME(void *destination, int value, u32 length);

void LEAF_NAME(RenderSurfaceSet **setAddress, u8 red, u8 green, u8 blue,
               u8 alpha)
{
    register RenderSurfaceSet *set __asm__("$16") = *setAddress;
    u16 packed;
    register u32 index __asm__("$17");

    if (set == 0) {
        return;
    }

    set->red = red;
    set->green = green;
    set->blue = blue;
    set->alpha = alpha;
    if (!(set->flags & 8)) {
        return;
    }

    packed = ((red << 8) & 0xF800) |
             ((green << 3) & 0x07C0) |
             ((blue >> 2) & 0x003E) | 1;
    set->state = 9;

    if (set->type == 8) {
        for (index = 0; index < set->count; index++) {
            FILL_NAME(set->surfaces[index], 0,
                      set->width * set->height * 2);
            *set->firstPixel = packed;
        }
    } else {
        for (index = 0; index < set->count; index++) {
            FILL_NAME(set->surfaces[index], packed,
                      set->width * set->height * 2);
        }
    }
}
