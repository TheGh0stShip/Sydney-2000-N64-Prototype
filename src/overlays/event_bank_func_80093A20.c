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
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern void func_80097504(void *obj);
extern void func_800AC334(void *obj);
extern void func_800ADC1C(void *obj);
extern void func_8007620C(void *obj);
extern void func_800D29E0(void *obj);
extern void func_800B35F0(void *obj);
extern void func_8001A248(void *obj);
extern void func_800BBD78(void *list, int id, int a, int b, int c);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_800AA658(void *list, void *slot);

typedef struct {
    short offset;
    short pad;
    void (*func)();
} VEntry;

void func_80093A20(unsigned char *object)
{
    unsigned char *p;
    unsigned char *player;
    VEntry *entry;
    int idx;

    func_80097504(object + 24188);
    p = object + 29452;
    func_800AC334(p);
    func_800ADC1C(p);
    player = *(unsigned char **)(object + 22988);
    if (player == 0) {
        return;
    }
    idx = player[424];
    if (idx != 8) {
        D_800FC270->entries[idx].active = 0;
    }
    func_8007620C(object);
    p = player + 812;
    func_800AC334(p);
    func_800D29E0(p);
    p = player + 2212;
    func_800AC334(p);
    func_800D29E0(p);
    func_800ADC1C(p);
    p = player + 3612;
    func_800AC334(p);
    func_800B35F0(p);
    func_800ADC1C(p);
    p = player + 3832;
    func_800AC334(p);
    func_800B35F0(p);
    func_800ADC1C(p);
    p = player + 4052;
    func_800AC334(p);
    func_800ADC1C(p);
    if (*(int *)(player + 4264) != 0) {
        func_8001A248(player + 4264);
    }
    func_800BBD78(D_800F2AD8, (signed char)player[427], 0, 0, 5);
    func_800BBD78(D_800F2AD8, (signed char)player[427], 1, 0, 2);
    func_800AACB0(D_800F26E0, player, 0);
    entry = (VEntry *)(*(unsigned char **)(player + 180) + 24);
    entry->func(player + entry->offset);
    entry = (VEntry *)(*(unsigned char **)(player + 180) + 8);
    entry->func(player + entry->offset, 2);
    func_800AA658(D_800F2758, object + 22988);
}
