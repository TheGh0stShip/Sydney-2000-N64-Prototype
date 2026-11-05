/* Flush pending text codes into the current run until the output is full.
 * Code 0xFFF1 does not increment the glyph count. Apply the pending cursor
 * advance and reset the pending state even when the output limit stops copying.
 * N64 big-endian MIPS o32; func_800B25AC, rebuilt exact over 0xC4 bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef char pending_text_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char pending_text_integer_width[sizeof(u32) == 4 ? 1 : -1];
typedef char pending_text_code_width[sizeof(u16) == 2 ? 1 : -1];
extern u8 pendingCodeCount;
extern u16 pendingAdvance;
extern u16 *pendingRead;
extern u16 pendingCodes[];
extern u16 runBufferEnd;
extern u16 *runOutput;
extern u8 runGlyphCount;
extern u16 runCursor;
void func_800B25AC(void) {
    u32 remaining=pendingCodeCount;
    if(remaining) {
        pendingRead=pendingCodes;
        while(1) {
            if(runOutput>&runBufferEnd) break;
            *runOutput=*pendingRead;
            if(*runOutput!=0xFFF1) runGlyphCount++;
            runOutput++;
            pendingRead++;
            if(!(u8)--remaining) break;
        }

        {
            u32 advance=pendingAdvance;
            pendingAdvance=0;
            pendingCodeCount=0;
            runCursor+=advance;
            pendingRead=pendingCodes;
        }
    }
}
