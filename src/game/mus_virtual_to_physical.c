#ifndef LEAF_NAME
#define LEAF_NAME musVirtualToPhysical
#endif
#ifndef FIND_REGION_NAME
#define FIND_REGION_NAME findDmaRegion
#endif
#ifndef PHYSICAL_NAME
#define PHYSICAL_NAME virtualToPhysical
#endif

typedef struct Region {
    int pad0[3];
    unsigned int base;
    unsigned int address;
} Region;

extern Region *FIND_REGION_NAME(unsigned int address);
extern unsigned int PHYSICAL_NAME(unsigned int address);

unsigned int LEAF_NAME(unsigned int address)
{
    Region *region;

    region = FIND_REGION_NAME(address);
    if (region == 0)
        return PHYSICAL_NAME(address);
    if ((address & 0xFF000000) == 0xFF000000) {
        address &= 0xFFFFFF;
        address += 0x140000;
    }
    return PHYSICAL_NAME(region->address + address - region->base);
}
