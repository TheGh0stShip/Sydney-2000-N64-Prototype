typedef struct SmallEventRecord {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    short field_10;
    short field_12;
} SmallEventRecord;

void func_800DAD30(unsigned char *object)
{
    SmallEventRecord *record = (SmallEventRecord *)(object + 0x60AC);
    unsigned int count = 8;

    do {
        record->field_00 = -0x1E00;
        record->field_04 = -0x1E00;
        record->field_08 = -0x1E00;
        record->field_0C = -0x1E00;
        record->field_10 = 0;
        record->field_12 = 0;
        record++;
        count--;
    } while ((count & 0xFF) != 0);
}
