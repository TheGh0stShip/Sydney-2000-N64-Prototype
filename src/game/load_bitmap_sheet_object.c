#ifndef LEAF_NAME
#define LEAF_NAME loadBitmapSheetObject
#endif

#ifndef LOAD_NAME
#define LOAD_NAME loadNamedResource
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif

#ifndef ALLOCATE_PALETTE_NAME
#define ALLOCATE_PALETTE_NAME allocatePaletteHandle
#endif

typedef unsigned long long u64;
typedef signed int s32;
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
    u32 flags;
    u32 enabled;
    u32 frames;
    u8 padding10[2];
    u16 stepX;
    u8 padding14[2];
    u16 stepY;
    u32 depth;
} BitmapSheetHeader;

typedef struct {
    u8 rgb[0x300];
} SheetPalette;

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
    u8 lastFrame;
    u8 frame;
    u8 frameCount;
    u8 padding2F[0xD];
    u32 depth;
    u8 padding40[8];
    void **bitData;
    BitmapRecord *bitmaps;
    BitmapSheetHeader *sheet;
    u16 *palette;
    u8 padding58[0x28];
    u32 state;
} BitmapObject;

extern u8 memoryContext[];
extern char fallbackSheetName[];
extern char bitDataName[];
extern char bitmapsName[];
extern char paletteName[];
extern float bitmapUnitScale;
extern s32 sheetLoaded;
extern u64 objectTimerBase;
extern u32 objectTimerValue;
extern SheetPalette sheetPalette;

extern s32 LOAD_NAME(char *name, void *handle, void *context, s32 flags);
extern void ALLOCATE_NAME(void *context, void **handle, u32 size, char *name);
extern void ALLOCATE_PALETTE_NAME(void *context, void **handle, u32 size,
                                  char *name);

u32 LEAF_NAME(BitmapObject *object, char *name, u32 field04, u32 field08)
{
    BitmapSheetHeader *sheet;
    u8 *data;
    u32 frames;
    u32 i;
    s32 j;
    s32 k;
    u8 *rgb;

    object->field04 = field04;
    object->field08 = field08;
    object->sheet = 0;
    object->sheet = 0;
    sheetLoaded = 0;
    object->scaleX = bitmapUnitScale;
    object->scaleY = bitmapUnitScale;
    if (LOAD_NAME(name, &object->sheet, memoryContext, 0) == 0) {
        LOAD_NAME(fallbackSheetName, &object->sheet, memoryContext, 0);
    }

    sheet = object->sheet;
    object->count = sheet->count;
    object->flags = sheet->flags;
    object->enabled = sheet->enabled;
    object->stepX = sheet->stepX;
    object->stepY = sheet->stepY;
    object->depth = sheet->depth;
    frames = sheet->frames;
    sheetLoaded = 1;
    if (frames != 0) {
        object->frame = 0;
        object->frameCount = frames;
        object->stepX = (u8)frames;
        object->state |= 0x20;
        object->lastFrame = object->count / frames - 1;
        objectTimerBase = 0;
        objectTimerValue = 0x4786;
    }

    object->palette = 0;
    object->bitData = 0;
    object->bitmaps = 0;
    object->flags |= 8;
    ALLOCATE_NAME(memoryContext, (void **)&object->bitData,
                  (object->count + 1) * 4, bitDataName);
    ALLOCATE_NAME(memoryContext, (void **)&object->bitmaps,
                  (object->count + 1) * 16, bitmapsName);

    data = (u8 *)object->sheet + 0x1C;
    for (i = 0; i < object->count; i++) {
        u32 width = ((u32 *)data)[0];
        u32 height = ((u32 *)data)[1];

        object->width = width;
        object->height = ((u32 *)data)[1];
        data += 0x10;
        object->bitData[i] = data;
        object->bitmaps[i].width = object->bitmaps[i].height = width;
        object->bitmaps[i].x = object->bitmaps[i].y = 0;
        object->bitmaps[i].pixels = object->bitData[i];
        object->bitmaps[i].stride = height;
        object->bitmaps[i].reserved = 0;
        if (object->depth == 16) {
            data += width * height * 2;
        } else {
            data += width * height;
        }
    }

    if (object->depth == 8) {
        ALLOCATE_PALETTE_NAME(memoryContext, (void **)&object->palette, 0x200,
                              paletteName);
        sheetPalette = *(SheetPalette *)data;
        for (j = 0, k = 0; j < 0x300; j += 3, k++) {
            rgb = &sheetPalette.rgb[j];
            if (rgb[0] == 0 && rgb[1] == 0 && rgb[2] == 0) {
                object->palette[k] = ((rgb[0] << 8) & 0xF800) |
                                     ((rgb[1] << 3) & 0x7C0);
            } else {
                object->palette[k] = ((rgb[2] >> 2) & 0x3E) |
                                     (((rgb[0] << 8) & 0xF800) |
                                      ((rgb[1] << 3) & 0x7C0)) | 1;
            }
        }
    }

    object->state |= 0x46;
    return object->count;
}
