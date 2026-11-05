/* Expand resource bytes using control words, literals and overlapping
 * backward references. The header offset is native big-endian u32; control
 * words and reference tokens are assembled from little-endian byte fields.
 * The auxiliary cursor tracks input+1 for each control-word refill.
 * N64 MIPS o32; rebuilt exact: func_800D6BD0, 0x2CC bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {u32 reserved[3];u32 dataOffset;} ResourceHeader;
typedef char resource_decode_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char resource_decode_word_width[sizeof(u32) == 4 ? 1 : -1];
typedef char resource_decode_count_width[sizeof(u16) == 2 ? 1 : -1];
typedef char resource_decode_header_size[sizeof(ResourceHeader) == 0x10 ? 1 : -1];
typedef char resource_decode_offset[(unsigned long)&((ResourceHeader *)0)->dataOffset == 0xC ? 1 : -1];
static __inline__ u32 readInitialControl(u8 *p) {
    return ((u32)p[3]<<24)+((u32)p[2]<<16)+((u32)p[1]<<8)+p[0];
}
#define READ_CONTROL() do { \
        flags=((u32)control[2]<<24)+((u32)control[1]<<16)+((u32)control[0]<<8)+input[0]; \
        control+=4; input+=4; bits=32; \
} while(0)
u8 *func_800D6BD0(u8 *input,u8 *output) {
    u8 *control;
    u8 *reference;
    u32 flags;
    u16 bits=32;
    input+=((ResourceHeader*)input)->dataOffset;
    input+=0x10;
    flags=readInitialControl(input);
    input+=4;
    control=input+1;
    for(;;) {
        if(!(flags&1)) {
            control++;
            *output++=*input++;
        } else {
            flags>>=1;
            if(--bits==0) READ_CONTROL();
            if(flags&1) {
                u32 token;
                u16 low;
                register u32 high __asm__("v0");
                u16 length;
                u16 distance;
                low=*input++;
                control+=2;
                high=(u32)*input++<<8;
                /* Retain the two token operands until their original uses. */
                __asm__("" : "+r"(high));
                token=low+high;
                __asm__("" : : "r"(low) : "$3");
                distance=(u16)token>>3;
                reference=output+((s32)distance|-0x2000);
                if(token&7) length=(token&7)+2;
                else {
                    length=*input;
                    control++;
                    input++;
                    if(length&0x80) reference-=0x2000;
                    length&=0x7F;
                    if(length==1) return output;
                    if(length==0) {
                        length=*input++;
                        control+=2;
                        length|=(u16)*input++<<8;
                    } else length+=2;
                }
                while(length--) *output++=*reference++;
            } else {
                u32 remaining;
                u8 offset;
                control++;
                offset=*input++;
                flags>>=1;
                remaining=--bits;
                reference=output+((s32)offset|-0x100);
                *output++=*reference++;
                *output++=*reference++;
                if(remaining==0) READ_CONTROL();
                if(flags&1) {
                    *output++=*reference++;
                    *output++=*reference++;
                }
                flags>>=1;
                if(--bits==0) READ_CONTROL();
                if(flags&1) *output++=*reference;
            }
        }
        flags>>=1;
        if(--bits==0) READ_CONTROL();
    }
}
