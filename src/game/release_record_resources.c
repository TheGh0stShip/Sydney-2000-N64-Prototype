#ifndef LEAF_NAME
#define LEAF_NAME releaseRecordResources
#endif

#ifndef RELEASE_NAME
#define RELEASE_NAME releaseSlot
#endif

#ifndef FINALIZE_NAME
#define FINALIZE_NAME finalizeHandles
#endif

#ifndef RECORD_COUNT_NAME
#define RECORD_COUNT_NAME recordCount
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

#ifndef FINAL_HANDLE_NAME
#define FINAL_HANDLE_NAME finalHandle
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 commandContext[];
extern u32 RECORD_COUNT_NAME;
extern u8 RECORDS_NAME[];
extern u32 FINAL_HANDLE_NAME;
extern void RELEASE_NAME(void *context, u32 *slot);
extern void FINALIZE_NAME(void);

void LEAF_NAME(void) {
    register u32 index __asm__("$17");
    register u8 *record __asm__("$16");
    register u32 *slot __asm__("$18");
    register u8 *context __asm__("$20");

    index = 0;
    if (RECORD_COUNT_NAME != 0) {
        context = (u8 *)0x800F0000;
        record = RECORDS_NAME;
        slot = (u32 *)(record + 216);
        do {
            if (*(u32 *)(record + 216) != 0) {
                RELEASE_NAME(context + 0x2758, slot);
                *(u32 *)(record + 216) = 0;
            }
            slot = (u32 *)((u8 *)slot + 224);
            index++;
            record += 224;
        } while (index < RECORD_COUNT_NAME);
    }
    record = (u8 *)0x80040000;
    if (*(u32 *)(record + 0x79C4) != 0) {
        RELEASE_NAME(commandContext, (u32 *)(record + 0x79C4));
    }
    *(u32 *)(record + 0x79C4) = 0;
    RECORD_COUNT_NAME = 0;
    FINALIZE_NAME();
}
