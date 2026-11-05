extern void func_8001A248(void *object);

typedef struct {
    short offset;
    short pad;
    void (*func)(void *self);
} VEntry;

typedef struct {
    unsigned char data[180];
    unsigned char *vtable;
    unsigned char rest[28];
} Child;

typedef struct {
    unsigned char pad[0x8450];
    int handles[5];
    Child children[5];
} Owner;

void func_8008EE68(Owner *owner)
{
    unsigned int i;

    for (i = 0; i < 5; i++) {
        VEntry *entry;

        func_8001A248(&owner->handles[i]);
        entry = (VEntry *)(((Child *)((unsigned char *)owner + 0x8464))[i].vtable + 24);
        entry->func((unsigned char *)&owner->children[i] + entry->offset);
    }
}
