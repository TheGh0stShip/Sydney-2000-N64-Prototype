#ifndef LEAF_NAME
#define LEAF_NAME initializeRenderRecord
#endif

#ifndef DEFAULT_SCALE_NAME
#define DEFAULT_SCALE_NAME defaultScale
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RenderRecord {
    u32 words00[7];
    u32 identifier;
    float scales[2];
    u16 halfword28;
    u16 halfword2A;
    u8 bytes2C[3];
    u8 padding2F;
    u32 word30;
    u32 padding34;
    u32 word38;
    u32 padding3C;
    u16 colors[4];
    u32 words48[2];
    u32 word50;
    u8 padding54[0x2C];
    u32 word80;
} RenderRecord;

extern float DEFAULT_SCALE_NAME;

void LEAF_NAME(RenderRecord *record) {
    record->colors[0] = record->colors[1] = record->colors[2] = record->colors[3] = 0xFF;
    record->words00[0] = 0;
    record->words00[1] = 0;
    record->words00[2] = 0;
    record->words00[3] = 0;
    record->words00[4] = 0;
    record->words00[5] = 0;
    record->words00[6] = 0;
    record->halfword2A = 0;
    record->halfword28 = 0;
    record->words48[0] = 0;
    record->words48[1] = 0;
    record->identifier = 0x1234;
    record->word30 = 0;
    record->word38 = 0;
    record->word50 = 0;
    record->bytes2C[0] = 0;
    record->bytes2C[1] = 0;
    record->bytes2C[2] = 0;
    record->word80 = 0;
    record->scales[0] = DEFAULT_SCALE_NAME;
    record->scales[1] = DEFAULT_SCALE_NAME;
}
