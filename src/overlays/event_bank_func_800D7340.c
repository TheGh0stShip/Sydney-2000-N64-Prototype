typedef struct {
    char pad[104];
    int volume;
} SoundPlayer;

typedef struct {
    short delta;
    short pad;
    void (*fn)();
} VEntry;

typedef struct {
    VEntry entries[4];
} VTable;

typedef struct {
    int base;
    int saved;
    int active;
} Timer;

extern SoundPlayer D_800F1AE0;
extern Timer D_800445F0;
extern char D_800F4D00[];
extern int D_800F13F0;
extern void func_8001D5D8(SoundPlayer *sp, int handle, int vol, int fade, int a, int b);
extern int func_8001D4B8(SoundPlayer *sp, int id, int a, int loop);
extern void func_8001D640(SoundPlayer *sp, int handle, int vol);
extern void func_800A62EC(void *p);
extern void func_8009BB88(int a, int b);
extern void func_800A3394(SoundPlayer *sp, int a, int b, int c);
extern void func_80008540(Timer *t);
extern void func_80099FE4(void *p);
extern void func_80076564(void *obj, int a, int b, int c);
extern void func_800ADC54(void *p, int mask);
extern void func_800ADC38(void *p);
extern void func_800AC25C(void *obj, int a, int b, int c);

static inline int scale_volume(int volume, int factor)
{
    return (volume * factor) >> 15;
}

void func_800D7340(char *obj)
{
    int handle;
    unsigned char mode;
    char *ctl;
    VTable *vt;
    int v;
    char *cfg;
    int old = *(int *)(obj + 24992);

    func_8001D5D8(&D_800F1AE0, old, 0, 15, 1, 0);
    handle = func_8001D4B8(&D_800F1AE0, 96, 0, -1);
    func_8001D640(&D_800F1AE0, handle, 0);
    func_8001D5D8(&D_800F1AE0, handle, scale_volume(D_800F1AE0.volume, 16383), 15, 0, 0);
    *(int *)(obj + 24980) = handle;
    func_800A62EC(obj + 14520);
    *(unsigned char *)(obj + 1556) = 0;
    mode = *(unsigned char *)(obj + 1557);
    if (mode != 5) {
        *(unsigned char *)(obj + 1558) = mode;
        *(unsigned char *)(obj + 1557) = 5;
        func_8009BB88(5, 1);
        func_800A3394(&D_800F1AE0, 16383, 32767, 32767);
        if (D_800445F0.active == 0) {
            D_800445F0.saved = D_800445F0.base;
            func_80008540(&D_800445F0);
            D_800445F0.active = 1;
        }
    }
    func_80099FE4(obj + 20220);
    func_80076564(obj, 150, 0, 0);
    cfg = D_800F4D00;
    ctl = obj + 19952;
    vt = *(VTable **)(ctl + 180);
    vt->entries[2].fn(ctl + vt->entries[2].delta, cfg);
    func_800ADC54(ctl, 1 << *(int *)(cfg + 216));
    *(unsigned char *)(ctl + 176) = 1;
    func_800ADC38(ctl);
    func_800AC25C(obj, 91, 18, 0);
    v = *(int *)(obj + 1628);
    if (v == 0)
        v = 1;
    D_800F13F0 = v;
    *(int *)(obj + 24932) = 0;
    *(unsigned char *)(obj + 1551) = 8;
}
