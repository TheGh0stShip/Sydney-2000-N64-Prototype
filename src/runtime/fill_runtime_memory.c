/* func_800B3AFC: aligned word-pattern fill, with byte-sized edges.
 * The caller supplies the full 32-bit word; edge bytes use its low byte.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef char check_fill_word[sizeof(u32) == 4 ? 1 : -1];
typedef char check_fill_pointer[sizeof(void *) == 4 ? 1 : -1];
extern u32 runtimeCopyStatistics[];

void func_800B3AFC(u8 *destination, u32 value, u32 size) {
    u32 count;
    u8 *end;
    register u8 *tail __asm__("$3");
    runtimeCopyStatistics[1]++;
    runtimeCopyStatistics[3] += size;
    if (size < 8) {
        if (size) {
            end = destination + size;
            do { *destination++ = value; } while (destination != end);
        }
        return;
    }
    count = (u32)destination & 3;
    if (count) {
        count = 4 - count;
        size -= count;
        end = destination + count;
        do { *destination++ = value; } while (destination != end);
    }
    if (size >= 256) {
        count = size & ~15;
        size -= count;
        end = destination + count;
        tail = destination + 12;
        do {
            ((u32 *)destination)[0] = value;
            ((u32 *)tail)[-2] = value;
            ((u32 *)tail)[-1] = value;
            ((u32 *)tail)[0] = value;
            tail += 16;
            destination += 16;
        } while (destination != end);
    }
    count = size & ~3;
    end = destination + count;
    if (count) {
        size -= count;
        do { *(u32 *)destination = value; destination += 4; } while (destination != end);
    }
    if (size) {
        end = destination + size;
        do { *destination++ = value; } while (destination != end);
    }
}
