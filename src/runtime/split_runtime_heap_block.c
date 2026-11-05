/* Stamp an allocation and split off a free block when space remains.
 * Runtime heap overhead is a16-byte header plus a4-byte size footer.
 */
typedef unsigned char u8;
typedef signed int s32;
void func_800AA724(void *heap, void **output, s32 size, const u8 *tag, u8 *inputBlock) {
    register u8 character __asm__("$10") = 0;
    register u8 *block __asm__("$8") = inputBlock;
    register u8 index __asm__("$9") = 0;
    register s32 previousSize __asm__("$3");
    register s32 span __asm__("$2");
    register u8 last __asm__("$4");
    register u8 *footer __asm__("$5");
    *output = block + 16;
    block[9] = 0;
    do {
        register unsigned int outputIndex __asm__("$3") = index;
        register unsigned int inputIndex __asm__("$2") = character;
        __asm__("" : "=r"(outputIndex), "=r"(inputIndex)
                    : "0"(outputIndex), "1"(inputIndex));
        block[outputIndex] = tag[inputIndex];
        if (tag[inputIndex]) character++;
        index++;
    } while (index < 8);
    previousSize = *(s32 *)(block + 12);
    if (size + 28 < previousSize) {
        last = block[11];
        span = size + 16;
        footer = block + span;
        block[11] = 0;
        *(s32 *)(block + 12) = size;
        block = footer + 4;
        span = 'E';
        previousSize -= 20;
        previousSize -= size;
        *(s32 *)footer = size;
        block[0] = span;
        footer = (u8 *)((unsigned int)previousSize + (unsigned int)block);
        block[1] = 'M';
        block[2] = 'P';
        block[3] = 'T';
        block[4] = 'Y';
        block[5] = 0;
        block[6] = 0;
        block[7] = 0;
        block[8] = 0;
        block[9] = 0xFF;
        block[10] = 0;
        *(s32 *)(block + 12) = previousSize;
        block[11] = last;
        *(s32 *)(footer + 16) = previousSize;
    }
}
