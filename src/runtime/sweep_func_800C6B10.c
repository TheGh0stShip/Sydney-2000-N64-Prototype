/* Destroy the static array of eight objects in reverse order, calling each
 * element's virtual destructor (slot 1) with the "don't free" flag 2. */
typedef struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Elem {
    char pad[180];
    VEntry *vtbl;
    char rest[212 - 184];
} Elem;

extern Elem D_80101960[8];

void func_800C6B10(void)
{
    Elem *p;

    if (D_80101960 != 0) {
        p = D_80101960 + 8;
        while (p != D_80101960) {
            p--;
            p->vtbl[1].fn((char *)p + p->vtbl[1].delta, 2);
        }
    }
}
