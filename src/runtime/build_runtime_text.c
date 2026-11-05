/* Build a formatted glyph run from 16-bit text/control tokens. Commands
 * substitute indexed strings, integers, decimals, frame times and glyphs;
 * line/tab/fixed-advance commands update the shared run builder.
 * Big-endian N64 MIPS o32; func_800B1D60, 0x3F8 text plus 28 table/literal bytes.
 * Empty operand constraints preserve compiler value lifetimes, without adding
 * instructions. Missing argument arrays retain the original stack-value behavior. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {u16 advance,height;u8 reserved[12];} GlyphMetrics;
typedef struct {u16 count,spacing,height,reserved;GlyphMetrics *glyphs;} FontMetrics;
typedef struct {u8 reserved[0xD6];u16 fixedAdvance,reservedD8,lineCount;} TextObject;
typedef union {u32 bits;s32 integer;f32 real;u16 *text;} TextArgument;
typedef char text_builder_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char text_builder_integer_width[sizeof(u32) == 4 ? 1 : -1];
typedef char text_builder_float_width[sizeof(f32) == 4 ? 1 : -1];
typedef char text_builder_glyph_stride[sizeof(GlyphMetrics) == 0x10 ? 1 : -1];
typedef char text_builder_font_keys[(unsigned long)&((FontMetrics *)0)->glyphs == 8 ? 1 : -1];
typedef char text_builder_line_count[(unsigned long)&((TextObject *)0)->lineCount == 0xDA ? 1 : -1];
extern FontMetrics *fontSets[4],*runFont;
extern u16 digitAdvances[4];
extern u16 runCursor,*runOutput,runBuffer[],runTabCount,pendingAdvance,*pendingRead,pendingCodes[],specialAdvance,spaceAdvance;
extern u8 runGlyphCount,runSpaceCount,pendingCodeCount;
extern s16 runVerticalAdvance;
extern s32 fixedAdvanceEnabled;
extern u16 *func_800B2284(TextObject *,u16 *);
extern void func_800B2468(TextObject *);
extern void func_800B2670(TextObject *,s32);
extern void func_800B2DD8(TextObject *,s32,s16,s32);
extern void func_800B2F44(TextObject *,f32,u16,s32);
extern void func_800B3318(TextObject *,u16);
extern void func_800B25AC(TextObject *);
static __inline__ s32 buildTextCore(TextObject *object,TextArgument *variables,u16 *text,u32 fontIndex) {
    TextArgument value;
    u16 space,special,argumentIndex;
    runCursor=0;
    runGlyphCount=0;
    runSpaceCount=0;
    runOutput=runBuffer;
    runTabCount=0;
    pendingAdvance=0;
    pendingCodeCount=0;
    pendingRead=pendingCodes;
    runVerticalAdvance=0;
    fixedAdvanceEnabled=0;
    runFont=fontSets[fontIndex];
    space=runFont->glyphs[3].advance;
    special=digitAdvances[fontIndex];
    object->lineCount=0;
    specialAdvance=special;
    spaceAdvance=space;
    for(;;) {
parse_next:
        if(*text==0) break;
        while(*text>=3) text=func_800B2284(object,text);
        if(*text==1) {
            text++;
            switch(*text) {
            case 1:
                text++;
                argumentIndex=*text;
                if(variables) value=variables[argumentIndex];
                __asm__("" : "+m"(value));
                text++;
                switch(*text) {
                case 1: {
                    u16 *nested=value.text;
                    u32 current=*nested;
                    u16 first;
                    __asm__("" : "+r"(current));
                    first=current;
                    if(first!=1) {
                        if(!first) { text++; goto parse_next; }
                        do {
                            register TextObject *wordObject __asm__("a0")=object;
                            if(current>=3) {
                                __asm__("" : : "r"(wordObject));
                                do {
                                    nested=func_800B2284(wordObject,nested);
                                    wordObject=object;
                                    current=*nested;
                                } while(current>=3);
                            }
                            if(*nested==1) {
                                nested++;
                                if(*nested==3) {
                                    func_800B2468(object);
                                    nested++;
                                }
                                if(*nested==2) {
                                    u32 newline=2;
                                    do { nested++; } while(*nested==newline);
                                }
                            }
                            /* Reload the token on every completed nested command. */
                            __asm__("" : "+r"(nested));
                            current=*nested;
                        } while(current);
                        text++; goto parse_next;
                    } else {
                        nested++;
                        if(*nested==first) {
                            nested+=2;
                            if(*nested==5) func_800B3318(object,nested[1]);
                        }
                    }
                    text++;
                    break;
                }
                case 2: {
                    register TextObject *callObject __asm__("a0");
                    register s32 sign __asm__("a3");
                    s32 integerValue;
                    text++;
                    callObject=object;
                    sign=0;
                    integerValue=value.integer;
                    __asm__("" : : "r"(integerValue));
                    func_800B2DD8(callObject,integerValue,(s16)*text++,sign);
                    func_800B25AC(object);
                    break;
                }
                case 3: {
                    u16 places,width;
                    text++;
                    places=*text++;
                    width=*text;
                    if(width<10) text++;
                    else width=0;
                    text--;
                    func_800B2F44(object,value.real,places,width);
                    text++;
                    func_800B25AC(object);
                    break;
                }
                case 4: {
                    f32 seconds=(f32)value.integer/30.0f*0.00390625f;
                    register TextObject *callObject __asm__("a0");
                    s32 width;
                    __asm__("" : "+r"(text) : "f"(seconds) : "$4", "$7");
                    text++;
                    callObject=object;
                    width=0;
                    func_800B2F44(callObject,seconds,*text,width);
                    text++;
                    func_800B25AC(object);
                    break;
                }
                case 5: {
                    register TextObject *callObject __asm__("a0");
                    text++;
                    callObject=object;
                    func_800B3318(callObject,*text++);
                    break;
                }
                }
                break;
            case 2:
                func_800B2670(object,1);
                text++;
                break;
            case 3:
                func_800B2468(object);
                text++;
                break;
            case 4:
                text++;
                *runOutput=0xFFFF;
                runOutput++;
                fixedAdvanceEnabled=!fixedAdvanceEnabled;
                break;
            }
        }
        goto parse_next;
    }
    func_800B2670(object,1);
    return runVerticalAdvance-runFont->height+runFont->glyphs[4].height;
}
s32 func_800B1D60(TextObject *object,u32 fontIndex,u16 *text,TextArgument *variables) {
    return buildTextCore(object,variables,text,fontIndex);
}
