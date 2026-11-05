/* Runtime-stage C reconstruction: append a glyph code to the text run, flushing first when it would overflow the line. */
typedef unsigned char u8; typedef unsigned short u16; typedef short s16; typedef unsigned int u32;

typedef struct GlyphInfo {
    int unused0;
    int unused4;
    float advance;
} GlyphInfo;

extern u32 glyphTable[];
extern u16 lineLimit;
extern u8 runGlyphCount;
extern u16 runCursor;
extern s16 *runOutput;
extern GlyphInfo *func_8001A154(u32 *entry);
extern void func_800B2670(void *object, int arg);

void func_800B3318(void *object, u16 code) {
    if (code < 13) {
        GlyphInfo *glyph = func_8001A154(&glyphTable[code]);
        s16 advance = glyph->advance;

        if (runCursor + advance > lineLimit) {
            func_800B2670(object, 0);
        }
        *runOutput = code - 14;
        runOutput++;
        runGlyphCount++;
        runCursor += advance;
    }
}
