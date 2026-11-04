#ifndef LEAF_NAME
#define LEAF_NAME clearIndexedWordIfSet
#endif

#ifndef TABLE_PAGE
#define TABLE_PAGE 0x80000000
#endif

#ifndef TABLE_OFFSET
#define TABLE_OFFSET 0
#endif

#ifndef RECORD_SIZE
#define RECORD_SIZE 132
#endif

int LEAF_NAME(int index) {
    register char *table asm("$2") = (char *)TABLE_PAGE;
    register int offset asm("$3");
    int *slot;

    asm volatile ("" : "=r" (table) : "0" (table));
    table += TABLE_OFFSET;
    offset = index * RECORD_SIZE;
    asm volatile ("" : "=r" (offset) : "0" (offset));
    offset += (int)table;
    slot = (int *)offset;

    if (*slot != 0) {
        *slot = 0;
    }

    return 0;
}
