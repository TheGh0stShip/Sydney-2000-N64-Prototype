typedef struct { signed char used; char pad[43]; } Slot;
typedef struct { char p0[16]; int count; Slot *slots; } Pool;
extern Slot defaultSlot;

Slot *func_800EA114(Pool *pool, int i)
{
    Slot *s = pool->slots;
    int n = pool->count;
    if (i < 0) {
        i = 0;
        while (1) {
            if (i >= n) break;
            if (s[i].used == 0) return &s[i];
            i++;
        }
    } else if (i < n) {
        return &s[i];
    }
    return &defaultSlot;
}
