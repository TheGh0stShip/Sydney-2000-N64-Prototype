extern unsigned char *D_800FC270;
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];
extern unsigned char D_800F2758[];
extern void func_800AC334(void *obj);
extern void func_800ADC1C(void *obj);
extern void func_800CEE04(void *obj);
extern void func_80076B94(void *obj);
extern void func_80097504(void *obj);
extern void func_8009F84C(void *obj);
extern void func_800BC274(void *obj);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_800AC308(void *obj);
extern void func_800AA658(void *list, void *slot);

typedef struct {
    int active;
    char pad[56];
} GameRow;

typedef struct {
    float value;
    char pad[8];
} GameSpeed;

typedef struct {
    char pad0[72];
    GameRow rows[40];
    char pad1[2580 - 72 - 40 * 60];
    GameSpeed speeds[4];
} Game;

typedef struct {
    short offset;
    short pad;
    void (*func)();
} VEntry;

void func_8008D3C0(unsigned char *object)
{
    unsigned char *hi;
    unsigned char *p;
    unsigned char *player;
    VEntry *entry;
    float best;
    int mode;
    int idx;
    int state;
    int slot;

    best = 0.0f;
    hi = object + 0x8000;
    *(int *)(hi + 1088) = 1;
    p = object + 26356;
    func_800AC334(p);
    func_800ADC1C(p);
    func_800CEE04(object + 31844);
    func_80076B94(object);
    func_80097504(object + 26580);
    p = (unsigned char *)0x8184;
    p += (int)object;
    func_800AC334(p);
    func_800ADC1C(p);
    p = object + 23196;
    func_800AC334(p);
    func_8009F84C(p);
    player = *(unsigned char **)(object + 23004);
    if (player == 0) {
        return;
    }
    slot = player[424];
    if (slot != 8) {
        ((Game *)D_800FC270)->rows[slot].active = 0;
    }
    state = player[426];
    if (state < 4) {
        if (state != 0) {
            idx = (signed char)hi[1045];
            best = ((Game *)D_800FC270)->speeds[idx].value;
        }
    }
    if (*(int *)(D_800FC270 + 2560) == 5 && *(float *)(D_800FC270 + 3560) < best) {
        *(float *)(D_800FC270 + 3560) = best;
    }
    mode = *(int *)(D_800FC270 + 2560);
    if (mode == 4 || mode == 0 || mode == 1 || mode == 2) {
        if (object[0x8000 + 1047] != 4 && *(float *)(D_800FC270 + 1280) < best) {
            *(float *)(D_800FC270 + 1280) = best;
        }
    }
    if (*(int *)(D_800FC270 + 2560) == 4 && *(float *)(D_800FC270 + 1324) < best) {
        *(float *)(D_800FC270 + 1324) = best;
    }
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, player, 0);
    entry = (VEntry *)(*(unsigned char **)(player + 180) + 24);
    entry->func(player + entry->offset);
    func_800AC308(player);
    entry = (VEntry *)(*(unsigned char **)(player + 180) + 8);
    entry->func(player + entry->offset, 2);
    func_800AA658(D_800F2758, object + 23004);
}
