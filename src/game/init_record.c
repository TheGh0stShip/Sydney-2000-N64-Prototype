/* Record initializer shared with Nagano Winter Olympics '98. */
typedef signed short s16;

typedef struct {
    int first;
    int second;
    int third;
    s16 fourth;
    s16 fifth;
    int sixth;
} Record;

void func_8002D2F0(Record *record, int second, int third, int sixth)
{
    record->first = 0;
    record->second = second;
    record->third = third;
    record->fourth = 0;
    record->fifth = 0;
    record->sixth = sixth;
}
