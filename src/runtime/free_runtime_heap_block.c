/* Release a runtime allocation, validating footer sizes before coalescing.
 * Block payload starts16bytes after the header; footer occupies4bytes.
 */
typedef unsigned char u8;
typedef signed int s32;
extern unsigned int func_800AA650(void *heap);
void func_800AA658(void *heap, void **output) {
    register u8 *block __asm__("$7");
    register u8 *neighbor __asm__("$6");
    register s32 size __asm__("$9");
    register s32 neighborSize __asm__("$8");
    register s32 previousSize __asm__("$3");
    register s32 extent __asm__("$2");
    register s32 *footer __asm__("$10");
    register unsigned int last __asm__("$11");
    register u8 *data __asm__("$2") = (u8 *)*output;
    __asm__("" : "=r"(data) : "0"(data));
    if (data) {
        block = data - 16;
        previousSize = *(s32 *)(block + 12);
        footer = (s32 *)(data + previousSize);
        if (previousSize != *footer) return;
        size = previousSize;
        last = block[11];
        block[9] = 0xFF;
        if (last != 0xFF) {
            neighbor = (u8 *)footer + 4;
            if (neighbor[9] == 0xFF) {
                previousSize = *(s32 *)(neighbor + 12);
                extent = previousSize + 16;
                footer = (s32 *)((unsigned int)neighbor + extent);
                if (previousSize != *footer) return;
                extent = size + 20;
                size = extent + previousSize;
                last = neighbor[11];
            }
        }
        if (block[10] != 0xFF) {
            previousSize = *(s32 *)(block - 4);
            extent = previousSize + 20;
            neighbor = block - extent;
            neighborSize = *(s32 *)(neighbor + 12);
            if (neighborSize != previousSize) return;
            if (neighbor[9] == 0xFF) {
                block = neighbor;
                extent = size + 20;
                size = extent + neighborSize;
            }
        }
        block[11] = last;
        *(s32 *)(block + 12) = size;
        *footer = size;
        *output = 0;
        func_800AA650(heap);
    }
}
