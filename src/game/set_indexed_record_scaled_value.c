#ifndef LEAF_NAME
#define LEAF_NAME setIndexedRecordScaledValue
#endif
#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

typedef struct {
    char padding_00[0x18];
    int rawValue;
    char padding_1C[0x18];
    int handle;
    char padding_38[8];
} Record;

extern Record RECORDS_NAME[];
extern void HELPER_NAME(int handle, int value);

void LEAF_NAME(void *unused, int index, int value) {
    Record *record;

    if (index < 0) {
        return;
    }
    record = &RECORDS_NAME[index];
    record->rawValue = value;
    if (value < 0) {
        value += 127;
    }
    HELPER_NAME(record->handle, value >> 7);
}
