typedef struct {
    char pad0[56];
    signed char value;
    char pad1[3];
} SlotSourceEntry;

typedef struct {
    char header[20];
    SlotSourceEntry entries[8];
} SlotSourceTable;

extern SlotSourceTable *D_800FC270;

typedef struct {
    char pad0[16];
    signed char first;
    signed char second;
    char pad1[24 - 18];
} SlotEntry;

void func_800BC104(SlotEntry *slots)
{
    int i = 0;
    unsigned char idx;
    int value;

    for (;; i++) {
        idx = i;
        if (idx >= 12) {
            return;
        }
        if (idx < 8) {
            value = D_800FC270->entries[idx].value;
            slots[idx].first = value;
            slots[idx].second = value;
        } else {
            slots[idx].first = -1;
            slots[idx].second = -1;
        }
    }
}
