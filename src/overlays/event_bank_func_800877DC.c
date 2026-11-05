typedef struct EventRecord {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    short field_20;
    short field_22;
} EventRecord;

void func_800877DC(unsigned char *object)
{
    EventRecord *record = (EventRecord *)(object + 0x52F0);
    unsigned int count = 8;

    do {
        record->field_00 = -0x1E00;
        record->field_04 = -0x1E00;
        record->field_08 = -0x1E00;
        record->field_0C = -0x1E00;
        record->field_14 = -0x1E00;
        record->field_10 = -0x1E00;
        record->field_18 = -0x1E00;
        record->field_1C = -0x1E00;
        record->field_20 = 0;
        record->field_22 = 0;
        record++;
        count--;
    } while ((count & 0xFF) != 0);
}
