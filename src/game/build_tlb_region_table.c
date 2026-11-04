#ifndef LEAF_NAME
#define LEAF_NAME buildTlbRegionTable
#endif
#ifndef CAPTURE_NAME
#define CAPTURE_NAME captureTlbEntries
#endif

typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u32 pageMask;
    u32 entryHi;
    u32 entryLo0;
    u32 entryLo1;
} CapturedTlbEntry;

typedef struct {
    s32 start;
    s32 end;
    u32 type;
} TlbRegion;

extern CapturedTlbEntry capturedTlbEntries[] __asm__("D_8007D3C4");
extern u32 physicalRegionMasks[] __asm__("D_80066C08");
extern TlbRegion tlbRegions[] __asm__("D_8007CD10");

extern u32 CAPTURE_NAME(void);

void LEAF_NAME(void)
{
    u32 asid = CAPTURE_NAME() & 0xFF;
    u32 index;

    for (index = 0; index < 32; index++) {
        CapturedTlbEntry *entry = &capturedTlbEntries[index];
        TlbRegion *region = &tlbRegions[index];
        u32 pageMask = entry->pageMask & 0x01FFE000;
        u32 even = entry->entryLo0;
        u32 odd = entry->entryLo1;
        u32 regionSize = 0;

        region->start = -1;
        region->type = 0;
        if ((even | odd) & 2) {
            u32 *candidate = physicalRegionMasks;
            regionSize = 0x1000;
            while (*candidate != pageMask) {
                if (*candidate & 0x80000000) {
                    regionSize = 0;
                    break;
                }
                candidate++;
                regionSize <<= 2;
            }
        }
        if (regionSize != 0) {
            u32 start;
            if ((even & odd & 3) != 3) {
                if ((even & 3) == 2 && (entry->entryHi & 0xFF) != asid) {
                    even &= ~2U;
                }
                if ((odd & 3) == 2 && (entry->entryHi & 0xFF) != asid) {
                    odd &= ~2U;
                }
            }
            start = entry->entryHi & 0xFFFFE000;
            if ((even & odd) & 2) {
                regionSize <<= 1;
            } else if (odd & 2) {
                start += regionSize;
            }
            region->start = start;
            region->end = start + regionSize - 1;
            region->type = 3;
        }
    }
}
