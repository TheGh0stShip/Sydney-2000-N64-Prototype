/* Append a glyph word with font/fixed advances, wrapping the current line
 * before flushing it; then append trailing code-3 spaces. An initial control
 * code bypasses word flushing. Return the next unconsumed code pointer.
 * N64 big-endian MIPS o32; func_800B2284, rebuilt exact over 0x1E4 bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u16 advance; u8 unused[14]; } GlyphMetrics;
typedef struct { u16 count,spacing; u32 unused; GlyphMetrics *glyphs; } FontMetrics;
typedef struct { u8 unused[0xD6]; u16 fixedAdvance; } TextObject;
typedef char text_word_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char text_word_integer_width[sizeof(u32) == 4 ? 1 : -1];
typedef char text_word_glyph_stride[sizeof(GlyphMetrics) == 0x10 ? 1 : -1];
typedef char text_word_font_keys[(unsigned long)&((FontMetrics *)0)->glyphs == 8 ? 1 : -1];
typedef char text_word_fixed_advance[(unsigned long)&((TextObject *)0)->fixedAdvance == 0xD6 ? 1 : -1];
extern FontMetrics *runFont;
extern u16 *pendingRead;
extern u16 pendingAdvance;
extern u8 pendingCodeCount;
extern s32 fixedAdvanceEnabled;
extern u16 specialAdvance;
extern u16 runCursor;
extern u16 lineLimit;
extern u16 *runOutput;
extern u16 spaceAdvance;
extern u8 runSpaceCount;
extern u16 runBufferEnd;
extern void func_800B2670(TextObject *,int);
extern void func_800B25AC(TextObject *);
u16 *func_800B2284(TextObject *object,u16 *text) {
    if(*text>=4) {
      do {
        u16 code=*text;
        if(code<runFont->count) {
            *pendingRead=code;
            if((s16)object->fixedAdvance>0 && fixedAdvanceEnabled) {
                pendingAdvance+=object->fixedAdvance;
            } else if((u32)(*text-4)<10) {
                pendingAdvance+=specialAdvance;
            } else {
                pendingAdvance+=runFont->glyphs[*text].advance+runFont->spacing;
            }
            pendingCodeCount++;
            pendingRead++;
        }
        text++;
      } while(*text>=4);
        if(pendingAdvance) pendingAdvance-=runFont->spacing;
        if(runCursor+pendingAdvance>lineLimit) func_800B2670(object,0);
        func_800B25AC(object);
    }
    while(*text==3) {
        *runOutput=3;
        runCursor+=spaceAdvance;
        text++;
        runSpaceCount++;
        runOutput++;
        if(runOutput>&runBufferEnd) break;
    }
    return text;
}
