typedef struct {
    int a;
    int b;
    char pad[8];
    signed char c;
    signed char d;
    short e;
    short f;
    short pad2;
} Entry;

typedef struct {
    Entry entries[12];
    int count;
    int extra;
} Table;

void func_800BC274(Table *t)
{
    unsigned int i;
    signed char none;
    Entry *e;

    i = 0;
    none = -1;
    e = t->entries;
next:
    if (i < 12) {
        i++;
        e->a = 0;
        e->b = 0;
        e->c = none;
        e->d = none;
        e->e = 0;
        e->f = 0;
        e++;
        goto next;
    }
    t->count = 0;
    t->extra = 0;
}
