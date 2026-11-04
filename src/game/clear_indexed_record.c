#ifndef LEAF_NAME
#define LEAF_NAME clearIndexedRecord
#endif
#ifndef FIRST_HELPER_NAME
#define FIRST_HELPER_NAME firstHelper
#endif
#ifndef CLEAR_HELPER_NAME
#define CLEAR_HELPER_NAME clearHelper
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

typedef struct {
    char padding_00[0x34];
    int handle;
    char padding_38[8];
} Record;

extern Record RECORDS_NAME[];
extern void FIRST_HELPER_NAME(int handle, int value);
extern void CLEAR_HELPER_NAME(void *destination, int value, int size);

void LEAF_NAME(void *unused, int index) {
    Record *record;

    if (index < 0) {
        return;
    }
    record = &RECORDS_NAME[index];
    FIRST_HELPER_NAME(record->handle, 0);
    CLEAR_HELPER_NAME(record, 0, sizeof(*record));
}
