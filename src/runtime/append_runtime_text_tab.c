/* Append code-2 tab data when the output buffer has room. Periodic tabs
 * advance to the next configured step; custom tabs select among eight stops.
 * Preserve the original full-table fallthrough and unsigned division behavior.
 * Big-endian N64 MIPS o32; rebuilt exact: func_800B2468, 0x144 bytes. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef char text_tab_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char text_tab_integer_width[sizeof(u32) == 4 ? 1 : -1];
typedef char text_tab_entry_width[sizeof(u16) == 2 ? 1 : -1];
extern u16 *runOutput;
extern u16 runBufferEnd;
extern int customTabsEnabled;
extern u16 runCursor;
extern u16 tabStep;
extern u16 runTabCount;
extern u16 runTabValues[];
extern s16 tabStops[];
void func_800B2468(void *unusedObject) {
    u16 index;
    if(runOutput>&runBufferEnd) return;
    if(!customTabsEnabled) {
        u32 cursor;
        u32 step;
        u32 advance;
        u16 position;
        register u16 nextCount __asm__("a0");
        u32 quotient;
        *runOutput=2;
        cursor=runCursor;
        step=tabStep;
        quotient=cursor/step;
        /* Keep the next counter register available after the quotient. */
        __asm__("" : : : "$4");
        advance=step-(cursor-quotient*step);
        {
            register u16 *output __asm__("v1")=runOutput;
            runOutput=output+1;
        }
        position=runTabCount;
        nextCount=position+1;
        runTabCount=nextCount;
        runTabValues[position]=advance;
        runCursor=cursor+advance;
    } else {
        *runOutput=2;
        for(index=0;index<8;index++) {
            if(tabStops[index]>=runCursor) break;
        }
        runTabValues[runTabCount++]=tabStops[index];
        runOutput++;
        runCursor=tabStops[index];
    }
}
