typedef struct {
    unsigned char pad[0x547C];
    signed char status[8];
    int values[8];
} EventEntries;

void func_80087EEC(EventEntries *object)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        object->values[i] = 0;
        object->status[i] = -1;
    }
}
