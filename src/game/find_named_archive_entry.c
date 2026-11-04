#ifndef LEAF_NAME
#define LEAF_NAME findNamedArchiveEntry
#endif

#ifndef RESOLVE_NAME
#define RESOLVE_NAME resolveNamedRecord
#endif

#ifndef READ_ROM_NAME
#define READ_ROM_NAME readRom
#endif

#ifndef COMPARE_NAME
#define COMPARE_NAME compareStrings
#endif

typedef unsigned int u32;

extern char archivePath[] __asm__("D_8005A6F8");
extern unsigned char archiveBuffer[] __asm__("D_800693B0");

extern int RESOLVE_NAME(char *path, unsigned char **cursor);
extern void READ_ROM_NAME(unsigned char *source, void *destination, u32 length);
extern int COMPARE_NAME(char *first, char *second);

u32 LEAF_NAME(char *name)
{
    unsigned char *cursor;
    register unsigned char *buffer __asm__("$21") = archiveBuffer;
    register unsigned char *scan __asm__("$17");
    register u32 remaining __asm__("$20");
    register u32 batch __asm__("$19");
    register u32 index __asm__("$18");
    register u32 work __asm__("$16");

    if (RESOLVE_NAME(archivePath, &cursor) == -1) {
        return 0;
    }

    READ_ROM_NAME(cursor, buffer, 8);
    cursor += 8;
    if (*(u32 *)buffer != 0x734600FE) {
        return 0;
    }

    remaining = ((u32 *)buffer)[1];
    do {
        batch = remaining;
        if (batch >= 57) {
            batch = 56;
        }
        work = batch * 40;
        READ_ROM_NAME(cursor, buffer, work);
        cursor += work;
        scan = buffer;
        for (index = 0; index < batch; index++) {
            work = *(u32 *)scan;
            scan += 8;
            if (COMPARE_NAME(name, (char *)scan) == 0) {
                return work;
            }
            scan += 32;
        }
        remaining -= batch;
    } while (remaining != 0);
    return 0;
}
