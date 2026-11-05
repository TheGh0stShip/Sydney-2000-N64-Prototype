/* Exact C reconstruction of func_800B3870 (runtime ROM 0x157160).
 * Forward copy with call/byte statistics and alignment-specific unrolling.
 * All widths, pointer arithmetic and counters use the N64 o32 ABI.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef char check_copy_word[sizeof(u32) == 4 ? 1 : -1];
typedef char check_copy_half[sizeof(u16) == 2 ? 1 : -1];
typedef char check_copy_pointer[sizeof(void *) == 4 ? 1 : -1];
extern u32 runtimeCopyStatistics[];

#define COPY_BYTES() do { \
    while (size) { \
        *destination++ = *source++; \
        size--; \
    } \
} while (0)

/* SN register constraints retain the two secondary unrolled cursors.
 * No instructions or object bytes are supplied by this source. */
#define COPY_FOUR(type) do { \
    type first, second, third, fourth; \
    second = ((const type *)sourceTail)[-2]; \
    third = ((const type *)sourceTail)[-1]; \
    fourth = ((const type *)sourceTail)[0]; \
    sourceTail += 4 * sizeof(type); \
    first = ((const type *)source)[0]; \
    source += 4 * sizeof(type); \
    ((type *)destination)[0] = first; \
    ((type *)destinationTail)[-2] = second; \
    ((type *)destinationTail)[-1] = third; \
    ((type *)destinationTail)[0] = fourth; \
    destinationTail += 4 * sizeof(type); \
    destination += 4 * sizeof(type); \
} while (0)

void func_800B3870(u8 *destination, const u8 *source, u32 size) {
    u32 alignment;
    u32 count;
    u8 *end;
    register u8 *destinationTail __asm__("$10");
    register const u8 *sourceTail __asm__("$9");
    runtimeCopyStatistics[0]++;
    runtimeCopyStatistics[2] += size;
    if (size < 8) {
        COPY_BYTES();
        return;
    }
    alignment = (u32)source ^ (u32)destination;
    if (!(alignment & 3)) {
        count = (u32)destination & 3;
        if (count) {
            count = 4 - count;
            size -= count;
            do {
                *destination++ = *source++;
                count--;
            } while (count);
        }
        if (size >= 256) {
            count = size & ~15;
            size -= count;
            end = destination + count;
            destinationTail = destination + 3 * sizeof(u32);
            sourceTail = source + 3 * sizeof(u32);
            do { COPY_FOUR(u32); } while (destination != end);
        }
        count = size & ~3;
        if (count) {
            size -= count;
            do {
                *(u32 *)destination = *(const u32 *)source;
                source += 4;
                count -= 4;
                destination += 4;
            } while (count);
        }
        COPY_BYTES();
    } else if (!(alignment & 1)) {
        if ((u32)destination & 1) {
            *destination++ = *source++;
            size--;
        }
        if (size >= 64) {
            count = size & ~7;
            size -= count;
            end = destination + count;
            destinationTail = destination + 3 * sizeof(u16);
            sourceTail = source + 3 * sizeof(u16);
            do { COPY_FOUR(u16); } while (destination != end);
        }
        count = size & ~1;
        if (count) {
            size -= count;
            do {
                *(u16 *)destination = *(const u16 *)source;
                source += 2;
                count -= 2;
                destination += 2;
            } while (count);
        }
        COPY_BYTES();
    } else {
        if (size > 16) {
            count = size & ~3;
            size -= count;
            end = destination + count;
            destinationTail = destination + 3 * sizeof(u8);
            sourceTail = source + 3 * sizeof(u8);
            do { COPY_FOUR(u8); } while (destination != end);
        }
        COPY_BYTES();
    }
}
