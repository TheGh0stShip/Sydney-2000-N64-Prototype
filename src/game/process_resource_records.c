#ifndef LEAF_NAME
#define LEAF_NAME processResourceRecords
#endif
#ifndef PROCESS_NAME
#define PROCESS_NAME processResourceRecord
#endif
#ifndef COUNT_NAME
#define COUNT_NAME resourceRecordCount
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME resourceRecords
#endif
#ifndef CURRENT_NAME
#define CURRENT_NAME currentResourceRecord
#endif
#ifndef SELECTED_NAME
#define SELECTED_NAME selectedResourceRecord
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 identifier;
    u8 padding04[12];
    u32 first;
    u32 second;
    u32 third;
    u32 fourth;
    u8 padding20[192];
} ResourceRecord;

extern u32 COUNT_NAME;
extern ResourceRecord RECORDS_NAME[];
extern u32 CURRENT_NAME;
extern u32 SELECTED_NAME;
extern void PROCESS_NAME(u32 identifier, u32 first, u32 second, u32 third,
                         u32 index, u32 fourth);

void LEAF_NAME(void) {
    u32 index;
    ResourceRecord *record;

    CURRENT_NAME = 0;
    SELECTED_NAME = (u32)-1;
    for (index = 0; index < COUNT_NAME; index++) {
        record = &RECORDS_NAME[index];
        if (record->identifier & 0x80000000) {
            record->identifier &= 0x7FFFFFFF;
            PROCESS_NAME(record->identifier, record->first, record->second,
                         record->third, index, record->fourth);
        }
    }
}
