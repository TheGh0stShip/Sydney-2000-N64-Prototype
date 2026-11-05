typedef struct {
    short delta;
    short pad;
    void (*fn)(char *object);
} VtableEntry;

typedef struct {
    char pad[180];
    VtableEntry *vtable;
    char pad2[28];
} Item;

typedef struct {
    char pad[30140];
    Item items[3];
} Owner;

void func_800AF198(Owner *self, unsigned int mask)
{
    unsigned int i;

    if (*((unsigned char *)self + 0x8000 + 286) != 5) {
        for (i = 0; i < 3; i++) {
            if (mask & (1 << i)) {
                self->items[i].vtable[8].fn((char *)&self->items[i] + self->items[i].vtable[8].delta);
            } else {
                self->items[i].vtable[9].fn((char *)&self->items[i] + self->items[i].vtable[9].delta);
            }
        }
    }
}
