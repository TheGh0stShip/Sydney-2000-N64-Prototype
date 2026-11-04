#ifndef LEAF_NAME
#define LEAF_NAME initializeDisplayRecords
#endif
#ifndef NEXT_VALUE_NAME
#define NEXT_VALUE_NAME nextDisplayValue
#endif
#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureDisplayValue
#endif
#ifndef REGISTER_NAME
#define REGISTER_NAME registerDisplayObject
#endif
#ifndef ADVANCE_NAME
#define ADVANCE_NAME advanceDisplayState
#endif
#ifndef FIRST_INDEX_NAME
#define FIRST_INDEX_NAME firstDisplayIndex
#endif
#ifndef SECOND_INDEX_NAME
#define SECOND_INDEX_NAME secondDisplayIndex
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME displayRecords
#endif
#ifndef CONTEXT_NAME
#define CONTEXT_NAME displayContext
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 first;
    u32 enabled;
    u16 index;
    u16 final;
} DisplayRecord;

extern u8 FIRST_INDEX_NAME;
extern u8 SECOND_INDEX_NAME;
extern DisplayRecord RECORDS_NAME[];
extern u8 CONTEXT_NAME[];
extern u32 NEXT_VALUE_NAME(void);
extern void CONFIGURE_NAME(u32 value, u32 firstIndex, u32 argument,
                           u32 secondIndex);
extern void REGISTER_NAME(void *context, u32 value, u32 enabled, u32 finalValue);
extern void ADVANCE_NAME(void);

void LEAF_NAME(void) {
    u32 count;
    u32 index;
    DisplayRecord *record;

    count = 0;
    while (count < 4) {
        index = SECOND_INDEX_NAME;
        record = &RECORDS_NAME[index];
        record->first = 0;
        record->enabled = 1;
        record->index = FIRST_INDEX_NAME;
        record->final = 0;

        CONFIGURE_NAME(NEXT_VALUE_NAME() & 0xFF, SECOND_INDEX_NAME, 0,
                       FIRST_INDEX_NAME);
        if (SECOND_INDEX_NAME == 0) {
            CONFIGURE_NAME(12, 0, 0, 8);
            REGISTER_NAME(CONTEXT_NAME, 12, 1, 12);
        }
        ADVANCE_NAME();
        count++;
        FIRST_INDEX_NAME++;
        SECOND_INDEX_NAME++;
    }
}
