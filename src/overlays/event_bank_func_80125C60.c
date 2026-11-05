typedef struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *self, int flags);
} VEntry;

typedef struct Racer {
    char pad000[0xB4];
    VEntry *vtable;
    char pad0B8[0x264 - 0xB8];
    int sound;
} Racer;

typedef struct Race {
    char pad0000[0x1AA];
    unsigned char mode;
    char pad01AB[0x2E0 - 0x1AB];
    int active;
    char pad02E4[0x81C - 0x2E4];
    char hud[0x6968 - 0x81C];
    Racer *racers[3];
} Race;

extern char D_800F2758[];

extern void func_8001786C(int sound);
extern void func_8007BF18(Racer *racer);
extern void func_800AA658(void *pool, void *slot);
extern void func_80083520(Race *race);
extern void func_8009D570(void *hud);

void func_80125C60(Race *race) {
    unsigned char i;

    i = 0;
    for (;;) {
        Racer *r;
        VEntry *vt;

        if (i >= 3) {
            break;
        }
        func_8001786C(race->racers[i]->sound);
        func_8007BF18(race->racers[i]);
        r = race->racers[i];
        vt = r->vtable;
        vt[1].fn((char *)r + vt[1].delta, 2);
        r = race->racers[i];
        vt = r->vtable;
        ((void (*)(void *))vt[3].fn)((char *)r + vt[3].delta);
        func_800AA658(D_800F2758, &race->racers[i]);
        i++;
    }
    if (race->mode != 4) {
        func_80083520(race);
    }
    func_8009D570(race->hud);
    race->active = 0;
}
