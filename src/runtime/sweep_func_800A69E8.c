/* Run two virtual methods (slots 3 and 9) on each of the five children. */
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
    char pad[188];
    Child children[5];
} Owner;

#define VCALL(obj, slot) ((&(obj))->vtbl[slot].fn((char *)&(obj) + (&(obj))->vtbl[slot].delta))

void func_800A69E8(Owner *owner)
{
    unsigned char i;

    for (i = 0; i < 5; i++) {
        VCALL(owner->children[i], 3);
        VCALL(owner->children[i], 9);
    }
}
