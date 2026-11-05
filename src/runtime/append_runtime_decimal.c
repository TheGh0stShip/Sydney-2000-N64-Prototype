/* Split a decimal into integer/fraction glyph runs and append the locale's
 * separator. Preserve truncation, strict greater-than-half rounding and the
 * original eight-place default when precision is zero.
 * Big-endian N64 MIPS o32; func_800B2F44, exact 0x200 text and eight literals. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {u16 advance;u8 unused[14];} GlyphMetrics;
typedef struct {u16 count,spacing;u32 unused;GlyphMetrics *glyphs;} FontMetrics;
typedef char decimal_text_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char decimal_text_integer_width[sizeof(s32) == 4 ? 1 : -1];
typedef char decimal_text_float_width[sizeof(f32) == 4 ? 1 : -1];
typedef char decimal_text_glyph_stride[sizeof(GlyphMetrics) == 0x10 ? 1 : -1];
typedef char decimal_text_font_keys[(unsigned long)&((FontMetrics *)0)->glyphs == 8 ? 1 : -1];
extern FontMetrics *runFont;
extern u16 *pendingRead;
extern u16 pendingAdvance;
extern u8 pendingCodeCount;
extern s32 textLocale;
extern void func_800B2DD8(void *,s32,s16,s32);
static __inline__ s32 splitDecimal(f32 value,u16 places,s32 *integer,s32 *fraction) {
    u16 precision=places;
    s32 whole;
    s32 part;
    u32 multiplier=1;
    s32 negative=0;
    u8 remaining;
    f32 residual;
    if(value<0.0f) negative=1;
    whole=(s32)value;
    if(places==0) precision=8;
    remaining=precision;
    residual=value-(f32)whole;
    while(remaining) {
        multiplier*=10;
        residual*=10.0f;
        remaining--;
    }
    part=(s32)residual;
    residual-=(f32)part;
    if(residual>0.5f) part++;
    if(part>=(s32)multiplier) {part=0;whole++;}
    *integer=whole;
    *fraction=part;
    if((f32)part<0.0f) *fraction=-part;
    return negative;
}
void func_800B2F44(void *object,f32 value,u16 places,s16 width) {
    s32 whole,fraction;
    s32 negative=splitDecimal(value,places,&whole,&fraction);
    func_800B2DD8(object,whole,-width,negative && whole==0);
    if(textLocale==2 || textLocale==4 || textLocale==5) {
        *pendingRead=0x4E;
        pendingRead++;
        pendingAdvance+=runFont->glyphs[0x4E].advance+runFont->spacing;
    } else {
        *pendingRead=0x43;
        pendingRead++;
        pendingAdvance+=runFont->glyphs[0x43].advance+runFont->spacing;
    }
    pendingCodeCount++;
    func_800B2DD8(object,fraction,(s16)places,0);
}
