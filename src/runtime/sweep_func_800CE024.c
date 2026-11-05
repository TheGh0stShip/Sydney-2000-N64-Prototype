typedef struct {
    short offset;
    void (*fn)(void *self);
} VirtualSlot;

typedef struct {
    char pad0[180];
    unsigned char *vtable;
    char pad1[212 - 184];
} Element;

typedef struct {
    Element header;
    Element elements[8];
} ElementGroup;

void func_800CE024(ElementGroup *self)
{
    unsigned char i;
    VirtualSlot *slot;

    for (i = 0; i < 8; i++) {
        slot = (VirtualSlot *)((self->elements + i)->vtable + 24);
        slot->fn((char *)&self->elements[i] + slot->offset);
        slot = (VirtualSlot *)((self->elements + i)->vtable + 72);
        slot->fn((char *)&self->elements[i] + slot->offset);
    }
}
