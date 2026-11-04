#ifndef LEAF_NAME
#define LEAF_NAME indexArchiveRecords
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateRuntimeMemory
#endif
#ifndef READ_NAME
#define READ_NAME readRuntimeData
#endif
#ifndef FIND_NAME
#define FIND_NAME findSubstring
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 field00;
    u32 field04;
    u32 active;
    char name[0x40];
} ArchiveRecord;

extern void *archiveStorage __asm__("D_800F2758");
extern void *runtimeAllocator __asm__("D_8004370C");
extern s32 archiveStorageSize __asm__("D_8004368C");
extern u8 *archiveData __asm__("D_80043674");
extern u32 archiveRecordCount __asm__("D_8004367C");
extern u32 firstActiveRecord __asm__("D_80043688");
extern u32 trailingRecordCount __asm__("D_80043690");
extern u32 leadingRecordCount __asm__("D_80043694");
extern u32 archivePageCount __asm__("D_80043680");
extern s32 firstGroupIndex __asm__("D_80043698");
extern s32 secondGroupIndex __asm__("D_8004369C");
extern s32 thirdGroupIndex __asm__("D_800436A0");
extern s32 fourthGroupIndex __asm__("D_800436A4");
extern s32 fifthGroupIndex __asm__("D_800436A8");
extern ArchiveRecord currentArchiveRecord __asm__("D_800436C0");
extern const char allocationSource[] __asm__("D_800004A0");
extern const char firstGroupName[] __asm__("D_800004AC");
extern const char secondGroupName[] __asm__("D_800004B4");
extern const char thirdGroupName[] __asm__("D_800004BC");
extern const char fourthGroupName[] __asm__("D_800004C4");
extern const char fifthGroupName[] __asm__("D_800004CC");

extern void ALLOCATE_NAME(void *allocator, void **output, u32 size,
                          const char *source);
extern void READ_NAME(const void *source, void *destination, u32 size);
extern char *FIND_NAME(const char *string, const char *substring);

void LEAF_NAME(s32 unused, u8 *data)
{
    u32 header[3];
    u32 i;

    (void)unused;
    ALLOCATE_NAME(runtimeAllocator, &archiveStorage, 0x7B8, allocationSource);
    archiveStorageSize = 0x7B8;
    READ_NAME(data, header, sizeof(header));

    archiveData = data;
    archiveRecordCount = header[0];
    firstActiveRecord = 0;
    firstGroupIndex = 0;
    secondGroupIndex = 0;
    thirdGroupIndex = 0;
    fourthGroupIndex = 0;
    fifthGroupIndex = 0;

    for (i = 0; i < archiveRecordCount; i++) {
        READ_NAME(data + 4 + i * sizeof(ArchiveRecord), &currentArchiveRecord,
                  sizeof(ArchiveRecord));
        if (currentArchiveRecord.active != 0) {
            firstActiveRecord = i;
            break;
        }
    }

    for (i = 0; i < archiveRecordCount; i++) {
        READ_NAME(data + 4 + i * sizeof(ArchiveRecord), &currentArchiveRecord,
                  sizeof(ArchiveRecord));
        if (firstGroupIndex == 0 && FIND_NAME(currentArchiveRecord.name, firstGroupName)) {
            firstGroupIndex = i;
        }
        if (secondGroupIndex == 0 && FIND_NAME(currentArchiveRecord.name, secondGroupName)) {
            secondGroupIndex = i;
        }
        if (thirdGroupIndex == 0 && FIND_NAME(currentArchiveRecord.name, thirdGroupName)) {
            thirdGroupIndex = i;
        }
        if (fourthGroupIndex == 0 && FIND_NAME(currentArchiveRecord.name, fourthGroupName)) {
            fourthGroupIndex = i;
        }
        if (fifthGroupIndex == 0 && FIND_NAME(currentArchiveRecord.name, fifthGroupName)) {
            fifthGroupIndex = i;
        }
    }

    trailingRecordCount = archiveRecordCount - firstActiveRecord;
    leadingRecordCount = archiveRecordCount - trailingRecordCount;
    archivePageCount = leadingRecordCount / 25;
}
