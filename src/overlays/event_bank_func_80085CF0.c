typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

#define VCALL(o, slot) ((VtEntry *)*(void **)((char *)(o) + 180))[slot].func((char *)(o) + ((VtEntry *)*(void **)((char *)(o) + 180))[slot].offset)
#define VCALL1(o, slot, a) ((VtEntry *)*(void **)((char *)(o) + 180))[slot].func((char *)(o) + ((VtEntry *)*(void **)((char *)(o) + 180))[slot].offset, a)

typedef struct Pool {
    char pad[12];
    void **top;
    unsigned short capacity;
    unsigned short count;
} Pool;

typedef struct Bank {
    char pad[16672];
    char *slots[4];
} Bank;

extern void func_800AACB0(void *, void *, int);
extern void func_800172CC(void *, int);
extern char D_800F26E0[];
typedef struct Entry {
    char pad[12];
    int active;
    char pad2[44];
} Entry;

typedef struct Table {
    char header[60];
    Entry entries[1];
} Table;

extern Table *D_800FC270;

void func_80085CF0(char *base, unsigned char index)
{
    char *obj;
    char *victim;
    char *sub;
    unsigned char kind;
    Pool *pool;

    obj = ((Bank *)base)->slots[index];
    if (obj == 0) {
        return;
    }
    func_800AACB0(D_800F26E0, obj, 0);

    sub = obj + 1036;
    if (sub != 0) {
        VCALL(sub, 3);
        VCALL(sub, 9);
        if (*(void **)(sub + 196) != 0) {
            func_800172CC(*(void **)(sub + 196), 1);
        }
    }
    sub = obj + 824;
    if (sub != 0) {
        VCALL(sub, 3);
        VCALL(sub, 9);
    }
    sub = obj + 1276;
    if (sub != 0) {
        VCALL(sub, 3);
        VCALL(sub, 9);
    }

    kind = obj[424];
    if (kind != 8) {
        D_800FC270->entries[kind].active = 0;
    }

    victim = ((Bank *)base)->slots[index];
    pool = (Pool *)(base + 16652);
    VCALL(victim, 3);
    func_800AACB0(D_800F26E0, victim, 0);
    if (pool->count < pool->capacity) {
        VCALL1(victim, 1, 2);
        *pool->top = victim;
        pool->top++;
        pool->count++;
    }
    ((Bank *)base)->slots[index] = 0;
}
