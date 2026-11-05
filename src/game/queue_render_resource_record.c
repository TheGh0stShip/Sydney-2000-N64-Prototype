/* Exact SN GCC 2.8 reconstruction of func_8000C68C, ROM 0xD28C..0xD544.
 * All resource identifiers, handles and record fields have N64 o32 widths.
 * Match: SN -O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb.
 * The differential validator isolates helper calls with deterministic stubs.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {
    u32 identifier;
    u32 resource;
    u16 flags;
    u8 unused0A[6];
    u32 arguments[4];
    u8 unused20[0xB8];
    u32 fieldD8;
    u32 unusedDC;
} QueuedResource;
typedef char check_queued_resource_size[sizeof(QueuedResource) == 0xE0 ? 1 : -1];
extern u32 resourceRecordCount;
extern QueuedResource resourceRecords[];
extern u32 currentResourceRecord;
extern u32 resourceRangeBase;
extern u32 resourceRangeLimit;
extern u32 resourceResolutionDisabled;
extern u32 resolvedResourceBytes;
extern u32 func_8000C394(u32 identifier);
extern u32 func_8000CA34(u32, u32, u32, u32, s32, u32);
extern u32 func_8000F2E8(u32 identifier, u32 *size);

u32 func_8000C68C(u32 identifier, u32 first, u32 second, u32 third, u32 fourth) {
    s32 freeIndex = -1;
    u32 index;
    register u32 initialCount __asm__("$2");
    register u32 count __asm__("$5");
    u32 resolved;
    u32 size;
    register QueuedResource *record __asm__("$3");
    QueuedResource *scanRecord;
    register u32 *argument __asm__("$4");
    u32 special;
    u32 valid;
    register u32 rangeValue __asm__("$2");
    register u32 rangeIndex __asm__("$4");

    if (identifier == 0x14AF || identifier == 0x14B0 ||
        identifier == 0x14B2 || identifier == 0x14B1 ||
        identifier == 0x101E || identifier == 0x101D ||
        identifier == 0x1020 || identifier == 0x101F ||
        identifier == 0x10B4 || identifier == 0x10B3 ||
        identifier == 0x10B6 || identifier == 0x10B5 ||
        identifier == 0xEE0 || identifier == 0xEDF ||
        identifier == 0xEE2 || identifier == 0xEE1) {
        special = 1;
    } else {
        special = 0;
    }
    if (special) return func_8000C394(identifier);
    if (!currentResourceRecord) {
        return func_8000CA34(identifier, first, second, third, -1, fourth);
    }
    if (identifier) {
        rangeIndex = identifier - 1;
        rangeValue = resourceRangeBase;
        valid = resourceRangeLimit;
        rangeValue += rangeIndex;
        valid = valid < rangeValue;
        valid ^= 1;
    } else {
        valid = 1;
    }
    if (!valid) return 0;
    index = 0;
    initialCount = resourceRecordCount;
    if (initialCount) {
        u32 identifierMask = 0x7FFFFFFF;
        u32 freeMarker = 0xFFFE;
        count = initialCount;
        scanRecord = resourceRecords;
        do {
            if (identifier == (scanRecord->identifier & identifierMask)) return index;
            if (scanRecord->identifier == freeMarker) freeIndex = index;
            index++;
            scanRecord++;
        } while (index < count);
    }
    if (!resourceResolutionDisabled) {
        resolved = func_8000F2E8(identifier, &size);
        for (index = 0; index < resourceRecordCount; index++) {
            if (resolved == resourceRecords[index].resource) {
                resolvedResourceBytes += size;
                return index;
            }
        }
    }
    if (freeIndex == -1) {
        freeIndex = resourceRecordCount++;
    }
    if (!resourceResolutionDisabled) {
        resourceRecords[freeIndex].resource = resolved;
    }
    {
        register u8 *base __asm__("$2") = (u8 *)resourceRecords;
        register s32 offset __asm__("$3") = freeIndex * 0xE0;
        argument = (u32 *)(base + 16);
        argument = (u32 *)((u8 *)argument + offset);
        record = (QueuedResource *)(base + offset);
        /* Keep the argument cursor separate from the record-base expression. */
        __asm__("" : "+r"(argument));
    }
    record->flags = 0;
    record->identifier = identifier | 0x80000000;
    record->fieldD8 = 0;
    *argument++ = first;
    *argument++ = second;
    *argument++ = third;
    *argument = fourth;
    return freeIndex;
}
