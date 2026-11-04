#ifndef LEAF_NAME
#define LEAF_NAME setIndexedRecordScaledField
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif
#ifndef SCALE_NAME
#define SCALE_NAME scale
#endif

typedef struct {
    int enabled;
    int active;
    int value;
} Record;

extern Record RECORDS_NAME[];
extern const float SCALE_NAME;

void LEAF_NAME(int *object, short index, float value) {
    register volatile int *objectCopy __asm__("$7");
    register Record *recordBase __asm__("$4");
    register int signedIndex __asm__("$3");
    int offset;
    register Record *record __asm__("$3");

    if ((unsigned short)index >= 4) {
        return;
    }
    objectCopy = object;
    recordBase = RECORDS_NAME;
    __asm__("" : "=r"(recordBase) : "0"(recordBase));
    signedIndex = (short)index;
    __asm__("" : "=r"(signedIndex) : "0"(signedIndex));
    offset = signedIndex * 3;
    record = (Record *)(offset * 4 + (char *)recordBase);
    __asm__("" : "=r"(record) : "0"(record));
    if (record->enabled == 0) {
        return;
    }
    if (*objectCopy == 0) {
        return;
    }
    if (record->active != 0) {
        record->value = (int)(value * SCALE_NAME);
    }
}
