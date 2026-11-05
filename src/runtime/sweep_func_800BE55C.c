typedef struct {
    char pad[36];
    int time;
} Entry;

typedef struct {
    Entry entries[20];
    unsigned char cursor;
} EntryRing;

extern EntryRing D_800F3890;
extern int D_800F2744;

Entry *func_800BE55C(void)
{
    EntryRing *ring = &D_800F3890;
    int now;

    if (ring->entries[ring->cursor].time > D_800F2744) {
        now = D_800F2744;
        do {
            if (++ring->cursor >= 20) {
                ring->cursor = 0;
            }
        } while (now < (ring->cursor + ring->entries)->time);
    }
    return &D_800F3890.entries[D_800F3890.cursor];
}
