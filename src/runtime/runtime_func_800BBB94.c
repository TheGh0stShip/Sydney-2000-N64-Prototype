typedef struct RuntimeEntry {
    int id;
    signed char marker;
    unsigned char first;
    unsigned char second;
    unsigned char third;
} RuntimeEntry;

typedef struct RuntimeEntryList {
    unsigned short capacity;
    unsigned short count;
    RuntimeEntry *entries;
} RuntimeEntryList;

void func_800BBB94(RuntimeEntryList *list)
{
    unsigned short remaining;
    RuntimeEntry *entry;

    remaining = list->capacity;
    entry = list->entries;
    while (remaining != 0) {
        entry->id = -7680;
        entry->marker = -1;
        entry->first = 0;
        entry->second = 0;
        entry->third = 0;
        entry++;
        remaining--;
    }
    list->count = 0;
}
