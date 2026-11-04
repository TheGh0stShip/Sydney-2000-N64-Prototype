#ifndef LEAF_NAME
#define LEAF_NAME initializeNamedArchive
#endif
#ifndef COPY_NAME
#define COPY_NAME copyString
#endif
#ifndef APPEND_NAME
#define APPEND_NAME appendString
#endif
#ifndef FIND_NAME
#define FIND_NAME findNamedArchiveEntry
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearBytes
#endif

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 command;
    u32 value;
    u8 padding08[0xD8];
} ArchiveDisplayRecord;

extern char archivePath[] __asm__("D_80069190");
extern char archivePrefix[] __asm__("D_8005A5F8");
extern char archiveName[] __asm__("D_8005A6F8");
extern const char defaultPath[] __asm__("D_800006D4");
extern const char pathSuffix[] __asm__("D_800006DC");
extern const char firstEntryName[] __asm__("D_800006E4");
extern const char secondEntryName[] __asm__("D_800006F0");
extern const char thirdEntryName[] __asm__("D_800006FC");
extern const char fourthEntryName[] __asm__("D_80000708");
extern const char fifthEntryName[] __asm__("D_80000714");
extern ArchiveDisplayRecord archiveDisplayRecords[] __asm__("D_80049A38");
extern u16 firstEntry __asm__("D_800499E0");
extern u16 secondEntry __asm__("D_800693A0");
extern u16 thirdEntry __asm__("D_800693A4");
extern u16 fourthEntry __asm__("D_800693A8");
extern u16 fifthEntry __asm__("D_800693AC");
extern u32 archiveRecordCount __asm__("D_80047988");
extern u8 *archiveRecords __asm__("D_8005A0A8");
extern u32 D_800479C8;
extern u32 D_8004798C;
extern u32 D_8004781C;
extern u32 D_800479A8;
extern u32 D_80047818;
extern u32 D_80047820;

extern void COPY_NAME(char *destination, const char *source);
extern void APPEND_NAME(char *destination, const char *source);
extern u32 FIND_NAME(const char *name);
extern void CLEAR_NAME(void *destination, u32 value, u32 size);

void LEAF_NAME(const char *name)
{
    u32 i;

    D_800479C8 = 0;
    D_8004798C = 0;
    D_8004781C = 0;
    D_800479A8 = 0;
    COPY_NAME(archivePath, name);
    COPY_NAME(archivePath, defaultPath);
    APPEND_NAME(archivePath, pathSuffix);
    COPY_NAME(archiveName, archivePath);

    for (i = 0; i < 300; i++) {
        archiveDisplayRecords[i].command = 0xDF000000;
        archiveDisplayRecords[i].value = 0;
    }

    firstEntry = (u16)FIND_NAME(firstEntryName);
    secondEntry = (u16)FIND_NAME(secondEntryName);
    thirdEntry = (u16)FIND_NAME(thirdEntryName);
    fourthEntry = (u16)FIND_NAME(fourthEntryName);
    fifthEntry = (u16)FIND_NAME(fifthEntryName);

    for (i = 0; i < archiveRecordCount; i++) {
        CLEAR_NAME(archiveRecords + i * 0x30, 0, 0x30);
    }
    D_80047818 = 0;
    D_80047820 = 0;
}
