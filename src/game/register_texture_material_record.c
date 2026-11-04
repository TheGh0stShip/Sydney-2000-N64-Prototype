#ifndef LEAF_NAME
#define LEAF_NAME registerTextureMaterialRecord
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u32 identifier;
    u8 padding04[12];
    Gfx commands[25];
    u32 fieldD8;
    u8 paddingDC[4];
} ResourceRecord;

extern u32 imageConversionEnabled __asm__("D_8004781C");
extern u32 resourceRecordCount __asm__("D_80047984");
extern u8 imageTileOutput[][0x800] __asm__("D_800479E0");
extern ResourceRecord resourceRecords[] __asm__("D_80049A28");

#define SHIFTL(v, s, w) ((u32)(((u32)(v)) & ((1 << (w)) - 1)) << (s))
#define SET_WORDS(pkt, first, second)                                          \
    {                                                                          \
        Gfx *_g = (Gfx *)(pkt);                                                \
        _g->w0 = (first);                                                      \
        _g->w1 = (second);                                                     \
    }

u32 LEAF_NAME(u32 identifier)
{
    u32 index;
    u32 tile = 0;
    ResourceRecord *record;
    Gfx *gfx;

    imageConversionEnabled = 1;
    switch (identifier) {
    case 0xEDF:
    case 0x101D:
    case 0x10B3:
    case 0x14AF:
        tile = 1;
        break;
    case 0xEE2:
    case 0x1020:
    case 0x10B6:
    case 0x14B2:
        tile = 2;
        break;
    case 0xEE1:
    case 0x101F:
    case 0x10B5:
    case 0x14B1:
        tile = 3;
        break;
    case 0xEE0:
    case 0x101E:
    case 0x10B4:
    case 0x14B0:
        break;
    }

    for (index = 0; index < resourceRecordCount; index++) {
        if (resourceRecords[index].identifier == identifier) {
            return index;
        }
    }

    if (resourceRecordCount >= 300) {
        return 0;
    }

    index = resourceRecordCount;
    gfx = resourceRecords[index].commands;
    record = &resourceRecords[index];
    record->identifier = identifier;
    record->fieldD8 = 0;
    SET_WORDS(gfx++, 0xE7000000, 0);
    SET_WORDS(gfx++, 0xE3001001, 0);
    SET_WORDS(gfx++, 0xD7000002, 0x7C007C00);
    SET_WORDS(gfx++, 0xFD100000, (u32)imageTileOutput[tile]);
    SET_WORDS(gfx++, 0xF5100000, 0x07014050);
    SET_WORDS(gfx++, 0xE6000000, 0);
    SET_WORDS(gfx++, 0xF3000000, 0x073FF100);
    SET_WORDS(gfx++, 0xE7000000, 0);
    SET_WORDS(gfx++, 0xF5100000 | SHIFTL(((32 * 2) + 7) >> 3, 9, 9),
              SHIFTL(5, 14, 4) | SHIFTL(5, 4, 4));
    SET_WORDS(gfx++, 0xF2000000,
              SHIFTL((32 - 1) << 2, 12, 12) |
                  SHIFTL((32 - 1) << 2, 0, 12));
    SET_WORDS(gfx++, 0xDF000000, 0);
    index = resourceRecordCount;
    resourceRecordCount = index + 1;
    return index;
}
