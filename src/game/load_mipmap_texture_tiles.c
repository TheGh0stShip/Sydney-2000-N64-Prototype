#ifndef LEAF_NAME
#define LEAF_NAME loadMipmapTextureTiles
#endif
#ifndef PHYSICAL_NAME
#define PHYSICAL_NAME virtualToPhysical
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 w0;
    u32 w1;
} GfxWords;

typedef union {
    GfxWords words;
    long long int forceAlignment;
} Gfx;

typedef struct {
    void *image;
    s32 format;
    s32 size;
} TextureInfo;

typedef struct {
    s32 lineWidth;
    s32 width;
    s32 height;
    s32 tmemOffset;
} MipmapLevel;

extern s32 tileZero __asm__("D_8005A814");
extern MipmapLevel mipmapLevels[] __asm__("D_8006A3B0");
extern s32 mipmapLineScale __asm__("D_8006A438");
extern u32 mipmapTexelCount __asm__("D_8006A43C");
extern s32 mipmapLevelCount __asm__("D_8006A440");

extern u32 PHYSICAL_NAME(void *address);

#define SHIFTL(v, s, w) (((u32)(v) & ((1U << (w)) - 1)) << (s))

#define SET_TEXTURE_IMAGE(pkt, fmt, siz, img)                            \
    {                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                 \
        _g->words.w0 = 0xFD000000 | SHIFTL(fmt, 21, 3) | SHIFTL(siz, 19, 2);   \
        _g->words.w1 = PHYSICAL_NAME(img);                                     \
    }

#define SET_TILE(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt,   \
                 shiftt, cms, masks, shifts)                             \
    {                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                 \
        _g->words.w0 = 0xF5000000 | SHIFTL(fmt, 21, 3) | SHIFTL(siz, 19, 2) |  \
                 SHIFTL(line, 9, 9) | SHIFTL(tmem, 0, 9);                \
        _g->words.w1 = SHIFTL(tile, 24, 3) | SHIFTL(palette, 20, 4) |          \
                 SHIFTL(cmt, 18, 2) | SHIFTL(maskt, 14, 4) |             \
                 SHIFTL(shiftt, 10, 4) | SHIFTL(cms, 8, 2) |             \
                 SHIFTL(masks, 4, 4) | SHIFTL(shifts, 0, 4);             \
    }

#define LOAD_SYNC(pkt)                                                   \
    {                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                 \
        _g->words.w0 = 0xE6000000;                                             \
        _g->words.w1 = 0;                                                      \
    }

#define LOAD_BLOCK(pkt, tile, lrs)                                       \
    {                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                 \
        _g->words.w0 = 0xF3000000;                                             \
        _g->words.w1 = SHIFTL(tile, 24, 3) |                                   \
                 SHIFTL(((lrs) < 0x7FF ? (lrs) : 0x7FF), 12, 12);        \
    }

#define SET_TILE_SIZE(pkt, tile, lrs, lrt)                               \
    {                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                 \
        _g->words.w0 = 0xF2000000;                                             \
        _g->words.w1 = SHIFTL(tile, 24, 3) | SHIFTL(lrs, 12, 12) |             \
                 SHIFTL(lrt, 0, 12);                                     \
    }

void LEAF_NAME(Gfx **displayList, TextureInfo *texture, void *image,
               u8 tile, u8 palette, u8 cms, u8 cmt, u8 masks, u8 maskt)
{
    s32 level;
    s32 levelMaskT;
    s32 levelShiftS;
    s32 levelMaskS;
    s32 levelShiftT;

    if (texture->size == 0) {
        SET_TEXTURE_IMAGE((*displayList)++, texture->format, 1, image);
        SET_TILE((*displayList)++, texture->format, 1, tileZero, 0, 7,
                 tileZero, tileZero, tileZero, tileZero, tileZero, tileZero,
                 tileZero);
        LOAD_SYNC((*displayList)++);
        LOAD_BLOCK((*displayList)++, 7, mipmapTexelCount >> 1);
    } else {
        SET_TEXTURE_IMAGE((*displayList)++, texture->format, texture->size,
                          image);
        SET_TILE((*displayList)++, texture->format, texture->size, tileZero,
                 0, 7, tileZero, tileZero, tileZero, tileZero, tileZero,
                 tileZero, tileZero);
        LOAD_SYNC((*displayList)++);
        LOAD_BLOCK((*displayList)++, 7, mipmapTexelCount);
    }

    level = 0;
    while (1) {
        if (mipmapLevelCount < level) {
            break;
        }
        levelMaskT = maskt - level;
        if (levelMaskT < 0) {
            levelMaskT = 0;
        } else {
            levelShiftT = level;
        }
        levelMaskS = masks - level;
        if (levelMaskS < 0) {
            levelMaskS = 0;
        } else {
            levelShiftS = level;
        }
        SET_TILE((*displayList)++, texture->format, texture->size,
                 (mipmapLevels[level].lineWidth * mipmapLineScale) >> 4,
                 mipmapLevels[level].tmemOffset >> 3, level + tile, palette,
                 cmt, levelMaskT, levelShiftT, cms, levelMaskS,
                 levelShiftS);
        SET_TILE_SIZE((*displayList)++, level + tile,
                      (mipmapLevels[level].width - 1) << 2,
                      (mipmapLevels[level].height - 1) << 2);
        level++;
    }
}
