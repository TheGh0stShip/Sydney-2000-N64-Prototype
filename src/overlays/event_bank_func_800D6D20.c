typedef struct {
    char pad[104];
    int volume;
} SoundPlayer;

extern SoundPlayer D_800F1AE0;
extern char D_800774E4[];
extern unsigned char D_80077610;
extern char D_800F26E0[];
extern int D_800F2744;
extern int D_8007735C;
extern void func_800D33A0(void *p, void *name, int a, int b);
extern int func_8001D4B8(SoundPlayer *sp, int id, int a, int loop);
extern void func_8001D640(SoundPlayer *sp, int handle, int vol);
extern void func_800AC25C(void *obj, int a, int b, int c);
extern int func_80017D54(void);
extern void func_800AB2A4(void *a, int b, int c, int d, int e, int f);

static inline int scale_volume(int volume, int factor)
{
    return (volume * factor) >> 15;
}

void func_800D6D20(char *obj)
{
    int t;
    unsigned char mode;

    if (*(unsigned char *)(obj + 1552) == 0) {
        if (*(unsigned char *)(obj + 1557) != 5) {
            func_800D33A0(obj + 12884, D_800774E4, 0, -1);
        }
        func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 227, 0, 1),
                      scale_volume(D_800F1AE0.volume, 32767));
        t = *(int *)(obj + 24928);
        mode = D_80077610;
        *(unsigned char *)(obj + 1551) = 11;
        *(int *)(obj + 24924) = t;
        *(int *)(obj + 24936) = t + 11520;
        *(unsigned char *)(obj + 1552) = mode;
        func_800AC25C(obj, 91, 14, 0);
        if (func_80017D54()) {
            func_800AB2A4(D_800F26E0, D_800F2744, 14, D_8007735C, 0, 0);
        }
    }
}
