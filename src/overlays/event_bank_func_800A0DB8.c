typedef struct EventEntry {
    unsigned char kind;
    unsigned char arg;
    short timer;
    char pad4[8];
} EventEntry;

typedef struct EventBank {
    char pad0[2572];
    unsigned char count;
    char pad2573[3];
    EventEntry entries[1];
} EventBank;

extern EventBank *D_800FC270;
extern void func_800A0C8C(unsigned char *self);
extern void func_800A0D48(unsigned char *self);

void func_800A0DB8(unsigned char *self)
{
    unsigned char phase = self[24041];

    if (phase == 0 || phase == 5) {
        while (self[24037] < self[24036]) {
            while (self[24038] < D_800FC270->count) {
                if (self[24124] == 0) {
                    func_800A0C8C(self);
                } else if (self[24124] == 1) {
                    func_800A0D48(self);
                }
                self[24124] = 0;
                self[24038]++;
            }
            self[24037]++;
        }
    } else if (phase == 4) {
        D_800FC270->entries[self[24038]].timer = -1;
    }
}
