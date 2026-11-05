typedef struct RuntimeAllocationRecord {
    short count;
    short capacity;
    void *owner;
    void *allocation;
    void *tail;
} RuntimeAllocationRecord;

extern char D_800F2758;
extern void func_800AA658(void *, void **);

void func_800EA368(RuntimeAllocationRecord *record)
{
    if (record->allocation != 0) {
        func_800AA658(&D_800F2758, &record->allocation);
    }

    record->allocation = 0;
    record->count = 0;
    record->owner = 0;
    record->tail = 0;
    record->capacity = 0;
}
