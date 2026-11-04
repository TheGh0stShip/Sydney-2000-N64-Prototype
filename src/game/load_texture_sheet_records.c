#ifndef LEAF_NAME
#define LEAF_NAME loadTextureSheetRecords
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseTextureSheets
#endif
#ifndef COPY_NAME
#define COPY_NAME copyString
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadNamedResource
#endif
#ifndef BUILD_NAME
#define BUILD_NAME buildTextureDisplayLists
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearMemory
#endif
#ifndef FREE_NAME
#define FREE_NAME freeMemory
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateZeroedGrid
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char *name;
    u16 unused04;
    u16 frameValue;
    u16 unused08;
    u16 lastFrameX;
    u32 unused0C;
} TextureSheetDescriptor;

typedef struct {
    u16 id;
    u16 unused02[2];
    u8 width;
    u8 height;
    u8 unused08[12];
} TextureSheetEntry;

typedef struct {
    u8 unused00[0x20];
    TextureSheetEntry entries[1];
} TextureSheet;

typedef struct {
    u16 x;
    u16 y;
    u16 offsetX;
    u16 offsetY;
    s32 index;
    s32 key;
} TextureFrame;

typedef struct {
    u16 frameCount;
    u16 cursor;
    u16 frameValue;
    TextureFrame *frames;
} TextureSheetRecord;

extern s32 alternateSheetSet __asm__("D_8005A83C");
extern TextureSheetDescriptor primarySheetDescriptors[] __asm__("D_80062434");
extern TextureSheetDescriptor alternateSheetDescriptors[] __asm__("D_80062474");
extern TextureSheet *textureSheets[] __asm__("D_800624B4");
extern s32 sheetRecordsCleared __asm__("D_800624CC");
extern TextureSheetRecord sheetRecords[] __asm__("D_800624D0");
extern TextureSheetRecord *activeSheetRecords[] __asm__("D_800FCB44");
extern u8 resourceContext[] __asm__("D_800F2758");

extern void RELEASE_NAME(void);
extern void COPY_NAME(char *, char *);
extern s32 LOAD_NAME(char *, void *, void *, s32);
extern void BUILD_NAME(TextureSheet *);
extern void CLEAR_NAME(void *, s32, s32);
extern void FREE_NAME(void *);
extern void *ALLOCATE_NAME(u32);

void LEAF_NAME(void)
{
    char path[256];
    TextureSheetDescriptor *descriptors;
    s32 sheet;
    u32 index;
    s32 frame;

    /* Reload the four texture sheets from the active descriptor set. */
    RELEASE_NAME();
    if (alternateSheetSet == 1) {
        descriptors = alternateSheetDescriptors;
    } else {
        descriptors = primarySheetDescriptors;
    }

    for (sheet = 0; sheet < 4; sheet++) {
        textureSheets[sheet] = 0;
        COPY_NAME(path, descriptors[sheet].name);
        if (LOAD_NAME(path, &textureSheets[sheet], resourceContext, 1) == 0) {
            return;
        }
        BUILD_NAME(textureSheets[sheet]);
    }

    if (sheetRecordsCleared == 0) {
        for (index = 0; index < 3; index++) {
            CLEAR_NAME(&sheetRecords[index], 0, sizeof(TextureSheetRecord));
            sheetRecordsCleared++;
        }
    }

    for (index = 0; index < 4; index++) {
        TextureSheetRecord *record = &sheetRecords[index];
        TextureSheetEntry *entry = textureSheets[index]->entries;

        /* Four leading frames precede one frame per sheet entry. */
        record->frameCount = 4;
        while (entry->id != 0xFFFF) {
            record->frameCount++;
            entry++;
        }
        record->frameValue = descriptors[index].frameValue;
        record->cursor = 0;
        if (record->frames != 0) {
            FREE_NAME(record->frames);
        }
        record->frames = 0;
        record->frames = ALLOCATE_NAME(record->frameCount);
        activeSheetRecords[index] = record;
    }

    for (index = 0; index < 4; index++) {
        TextureSheetRecord *record = &sheetRecords[index];
        TextureSheetEntry *entry = textureSheets[index]->entries;

        /* The first four frames share the first entry's dimensions. */
        for (frame = 0; frame < record->frameCount; frame++) {
            record->frames[frame].x = (u32)(float)entry->width;
            record->frames[frame].y = (u32)(float)entry->height;
            if (frame == 3) {
                record->frames[3].x = descriptors[index].lastFrameX;
            }
            record->frames[frame].x += 2;
            record->frames[frame].y += 2;
            record->frames[frame].index = frame;
            record->frames[frame].offsetX = 0;
            record->frames[frame].offsetY = 0;
            record->frames[frame].key = (index << 8) + frame;
            if (frame >= 3) {
                entry++;
            }
        }
    }
}
