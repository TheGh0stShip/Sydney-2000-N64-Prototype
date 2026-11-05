/* Format the 16-bit magnitude as digit glyphs, add width padding and the
 * negative/forced sign marker, then append the reversed digits to pending text.
 * Big-endian N64 MIPS o32; rebuilt exact: func_800B2DD8, 0x16C bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {u16 count,spacing;u32 unused;void *glyphs;} FontMetrics;
typedef char integer_text_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char integer_text_integer_width[sizeof(s32) == 4 ? 1 : -1];
typedef char integer_text_code_width[sizeof(u16) == 2 ? 1 : -1];
typedef char integer_text_font_spacing[(unsigned long)&((FontMetrics *)0)->spacing == 2 ? 1 : -1];
extern u16 *pendingRead;
extern u8 pendingCodeCount;
extern u16 pendingAdvance;
extern u16 specialAdvance;
extern FontMetrics *runFont;
void func_800B2DD8(void *object,s32 value,s16 width,s32 forceSign) {
    u16 digits[12];
    u16 *out;
    u16 magnitude;
    u16 quotient;
    s16 field=width;
    u16 padding;
    u8 count;
    if(width<0) {
        padding=0xFFF1;
        field=-width;
    } else padding=4;
    if(value<0) magnitude=(u32)0-(u32)value;
    else magnitude=value;
    if(value>0 && forceSign) field++;
    out=digits;
    count=0;
    for(;;) {
        quotient=magnitude/10;
        *out++=magnitude-quotient*10+4;
        count++;
        if((field && count>=field) || !quotient) break;
        magnitude=quotient;
    }
    if(field) {
        while(count<field) {
            *out++=padding;
            count++;
        }
    }
    if(value<0 || forceSign) {
        *out++=0x44;
        count++;
    }
    while(count) {
        --out;
        *pendingRead=*out;
        count--;
        pendingRead++;
        pendingAdvance+=specialAdvance+runFont->spacing;
        pendingCodeCount++;
    }
}
