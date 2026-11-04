#ifndef LEAF_NAME
#define LEAF_NAME resolveArchiveRecordIndex
#endif
#ifndef DECODE_NAME
#define DECODE_NAME decodePathString
#endif
#ifndef COPY_NAME
#define COPY_NAME copyString
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareArchiveName
#endif
#ifndef FIND_SUBSTRING_NAME
#define FIND_SUBSTRING_NAME findSubstring
#endif
#ifndef READ_NAME
#define READ_NAME copyRomBytes
#endif
#ifndef COMPARE_NAME
#define COMPARE_NAME compareStrings
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 archiveDecodeEnabled __asm__("D_80043670");
extern u8 *archiveRomRecords __asm__("D_80043674");
extern u32 archiveSelectedIndex __asm__("D_80043678");
extern u32 archiveRecordCount __asm__("D_8004367C");
extern u32 archivePageCount __asm__("D_80043680");
extern u32 archiveFirstIndex __asm__("D_80043688");
extern u32 firstTypeIndex __asm__("D_80043698");
extern u32 secondTypeIndex __asm__("D_8004369C");
extern u32 thirdTypeIndex __asm__("D_800436A0");
extern u32 fourthTypeIndex __asm__("D_800436A4");
extern u32 fifthTypeIndex __asm__("D_800436A8");
extern u8 *archiveRecordBuffer __asm__("D_8004370C");
extern const char firstTypeName[] __asm__("D_800004AC");
extern const char secondTypeName[] __asm__("D_800004B4");
extern const char thirdTypeName[] __asm__("D_800004BC");
extern const char fourthTypeName[] __asm__("D_800004C4");
extern const char fifthTypeName[] __asm__("D_800004CC");

extern void DECODE_NAME(char *output);
extern void COPY_NAME(char *output, const char *input);
extern void PREPARE_NAME(char *path);
extern char *FIND_SUBSTRING_NAME(const char *path, const char *part);
extern void READ_NAME(const void *source, void *destination, u32 size);
extern s32 COMPARE_NAME(const char *first, const char *second);

s32 LEAF_NAME(void *unused, const char *name, u32 ordinal)
{
    char path[256];
    char candidate[256];
    u32 page;
    u32 index;
    u32 count;

    (void)unused;
    if (name == 0) {
        if (ordinal == 0) {
            return -1;
        }
        ordinal--;
        archiveSelectedIndex = 0;
        ordinal += archiveFirstIndex;
        if (ordinal >= archiveRecordCount) {
            return -1;
        }
        return ordinal;
    }

    if (archiveDecodeEnabled != 0) {
        DECODE_NAME(path);
    } else {
        COPY_NAME(path, name);
    }
    PREPARE_NAME(path);
    archiveSelectedIndex = 0;
    if (FIND_SUBSTRING_NAME(path, firstTypeName) != 0) {
        archiveSelectedIndex = firstTypeIndex;
    } else if (FIND_SUBSTRING_NAME(path, secondTypeName) != 0) {
        archiveSelectedIndex = secondTypeIndex;
    } else if (FIND_SUBSTRING_NAME(path, thirdTypeName) != 0) {
        archiveSelectedIndex = thirdTypeIndex;
    } else if (FIND_SUBSTRING_NAME(path, fourthTypeName) != 0) {
        archiveSelectedIndex = fourthTypeIndex;
    } else if (FIND_SUBSTRING_NAME(path, fifthTypeName) != 0) {
        archiveSelectedIndex = fifthTypeIndex;
    }

    for (page = 0; page <= archivePageCount; page++) {
        count = 25;
        if (archiveSelectedIndex + count > archiveRecordCount) {
            count = archiveRecordCount - archiveSelectedIndex;
        }
        READ_NAME(archiveRomRecords + 4 + archiveSelectedIndex * 76,
                  archiveRecordBuffer, count * 76);
        for (index = 0; index < 25; index++) {
            if (archiveSelectedIndex + index > archiveFirstIndex) {
                return -1;
            }
            COPY_NAME(candidate, (char *)archiveRecordBuffer + index * 76 + 12);
            if (COMPARE_NAME(path, candidate) == 0) {
                return archiveSelectedIndex + index;
            }
        }
        archiveSelectedIndex += 25;
    }
    return -1;
}
