/* Debug-host memory-region initialization, ROM 0x29954..0x29AB8.
 * Verified with SN GCC 2.8 and the reviewed equivalent instruction
 * transformations in tools/verify_sn_normalized.py.
 * Region boundaries are 32-bit N64 virtual-address tokens.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 start, limit, flags; } DebugRegion;
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];
typedef char check_region_size[sizeof(DebugRegion) == 12 ? 1 : -1];
extern u8 debug_enabled, debug_response;
extern u32 debug_limits[];
extern DebugRegion debug_regions[];
extern int func_800282C0(void);
extern void func_800291C0(void);
extern void func_80028328(u32, u32);
extern void func_800282F8(int);

void func_80028D54(void) {
    int mask = func_800282C0();
    u32 size;
    u32 *source;
    volatile DebugRegion *destination;
    /* Keep the two transfer temporaries in the original caller-saved registers. */
    register u32 limit __asm__("$2");
    register u32 flags __asm__("$3");
    u32 start;

    func_800291C0();
    func_80028328(0xB1FFFFF0, 0);
    func_80028328(0xB1FFFFFC, 0);
    size = *(u32 *)0x80000318;
    debug_enabled = 1;
    debug_response = 0xFF;
    if (size > 0x3FFFFF) {
        if (!(size & 0x1FFFF)) {
            if (size <= 0x2000000) {
                size--;
                debug_limits[2] = size - 0x80000000;
                debug_limits[6] = size + 0xA0000000;
            }
        }
    }
    source = debug_limits;
    start = 0x80000000;
    while (*source < start) source += 2;
    size = 0;
    destination = debug_regions;
    do {
        destination->start = start;
        limit = *source++;
        size++;
        destination->limit = limit;
        flags = *source++;
        start = limit + 1;
        destination->flags = flags;
        destination++;
    } while (start);
    for (; size < 16; size++) {
        debug_regions[size].start = -1;
        debug_regions[size].flags = 0;
    }
    func_800282F8(mask);
}
