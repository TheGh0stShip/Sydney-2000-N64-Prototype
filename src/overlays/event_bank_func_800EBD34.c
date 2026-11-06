typedef struct {
    unsigned int flags;
    int pad[3];
} EventEntry;

typedef struct {
    char pad0[0x350];
    EventEntry *table;
    char pad354[0x380 - 0x354];
    unsigned char result;
    char pad381[0x413 - 0x381];
    unsigned char index;
} EventObject;

void func_800EBD34(EventObject *object, EventEntry *table)
{
    unsigned int flags;

    object->table = table;
    object->index = *(*(unsigned char **)((char *)object + 4) + 0x8C99);
    flags = object->table[object->index].flags;
    if ((flags & 0x11) && (flags & 0x0FF80000) > 0x00400000) {
        object->result = 0;
        return;
    }
    object->result = 1;
}
