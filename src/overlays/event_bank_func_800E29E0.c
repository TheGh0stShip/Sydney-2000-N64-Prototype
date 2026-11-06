typedef struct {
    unsigned char pad[0x6328];
    signed char status[8];
    int values[8];
} EventEntries;

void func_800E29E0(EventEntries *object)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        object->values[i] = 0;
        object->status[i] = -1;
    }
}
