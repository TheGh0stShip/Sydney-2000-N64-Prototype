typedef struct {
    unsigned short unk0;
    unsigned short start;
    unsigned char *entries;
} EntryTable;

unsigned char *func_800BBB04(EntryTable *table, int offset)
{
    short index = table->start + offset;

    if (index >= 0) {
        return table->entries + index * 8;
    }
    return 0;
}
