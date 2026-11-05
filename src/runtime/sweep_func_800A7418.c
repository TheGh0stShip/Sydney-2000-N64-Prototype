/* Run two virtual methods (slots 3 and 9) on each of the four children. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self);
} VEntry;

typedef struct Child {
    char pad[180];
    VEntry *vtbl;
    char rest[212 - 184];
} Child;

typedef struct Owner {
    char pad[204];
    Child children[4];
} Owner;

#define VCALL(obj, slot) ((&(obj))->vtbl[slot].fn((char *)&(obj) + (&(obj))->vtbl[slot].delta))

void func_800A7418(Owner *owner)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        VCALL(owner->children[i], 3);
        VCALL(owner->children[i], 9);
    }
}
