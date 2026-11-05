typedef struct Ext {
    char pad0[2821];
    unsigned char round;
    char pad1[2824 - 2822];
    int timer;
    char pad2[2832 - 2828];
    int counter;
    char pad3[2841 - 2836];
    unsigned char players;
    char pad4[3416 - 2842];
    int voice;
} Ext;

typedef struct Mixer {
    char pad0[104];
    int volume;
} Mixer;

extern char D_800F2AD8[];
extern int D_800F2728;
extern Mixer D_800F1AE0;
extern void func_8009BD50(int mode);
extern void func_800834F4(void *player);
extern void func_8009D8F0(void *hud);
extern void func_80073498(char *self);
extern void func_800AC334(void *obj);
extern void func_800BBD78(void *list, int id, int on, void *owner, int kind);
extern void func_800D771C(void *obj);
extern void func_800B4794(int on);
extern void func_80073178(char *self);
extern void func_8001D550(Mixer *mixer, int a);
extern int func_8001D4B8(Mixer *mixer, int id, int a, int b);
extern void func_8001D640(Mixer *mixer, int handle, int a);
extern void func_8001D5D8(Mixer *mixer, int handle, int volume, int pan, int a, int b);

static inline void Mixer_play(Mixer *mixer, int handle, int pan)
{
    int scale = 19660;

    func_8001D5D8(mixer, handle, mixer->volume * scale >> 15, pan, 0, 0);
}

void func_80078B00(char *self)
{
    Ext *ext;
    int handle;

    func_8009BD50(((unsigned char *)self)[1556]);
    func_800834F4(self + 1584);
    func_8009D8F0(self + 3660);
    ext = (Ext *)(self + 0x10000);
    if (ext->players >= 2) {
        func_800834F4(self + 28608);
        func_8009D8F0(self + 30684);
    }
    func_80073498(self);
    func_800AC334(self + 0x10A2C);
    func_800BBD78(D_800F2AD8, 12, 1, self, 2);
    func_800BBD78(D_800F2AD8, 13, 1, self, 2);
    D_800F2728 = 0;
    ext->timer = -7680;
    *(int *)(self + 172) = 0;
    ext->counter = 0;
    self[1556] = self[1557];
    func_800D771C(self + 0xD954);
    func_800B4794(1);
    ext->round++;
    func_80073178(self);
    func_800B4794(0);
    func_8001D550(&D_800F1AE0, 1);
    handle = func_8001D4B8(&D_800F1AE0, 95, 0, -1);
    func_8001D640(&D_800F1AE0, handle, 0);
    Mixer_play(&D_800F1AE0, handle, 45);
    ext->voice = handle;
}
