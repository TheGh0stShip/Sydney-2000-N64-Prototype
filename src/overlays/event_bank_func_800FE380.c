typedef struct WideEventRecord {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    short field_18;
    short field_1A;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
} WideEventRecord;

void func_800FE380(unsigned char *object)
{
    WideEventRecord *record = (WideEventRecord *)(object + 0x308);
    unsigned int count = 7;

    do {
        record->field_00 = 0;
        record->field_04 = 0;
        record->field_08 = 0;
        record->field_0C = 0;
        record->field_10 = 0;
        record->field_14 = 0;
        record->field_18 = 0;
        record->field_1A = 0;
        record->field_1C = 0;
        record->field_20 = 0;
        record->field_24 = 0;
        record->field_28 = 0;
        record++;
        count--;
    } while ((count & 0xFF) != 0);
}
