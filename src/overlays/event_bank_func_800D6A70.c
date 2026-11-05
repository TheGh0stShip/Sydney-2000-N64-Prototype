typedef struct {
    char pad[104];
    int volume;
} SoundPlayer;

extern SoundPlayer D_800F1AE0;
extern void func_8001D5D8(SoundPlayer *sp, int handle, int vol, int fade, int a, int b);
extern int func_8001D4B8(SoundPlayer *sp, int id, int a, int loop);
extern void func_8001D640(SoundPlayer *sp, int handle, int vol);
extern void func_80099D70(void *p, int a, float b);

static inline int scale_volume(int volume, int factor)
{
    return (volume * factor) >> 15;
}

void func_800D6A70(char *obj)
{
    int handle;
    int old;

    *(int *)(obj + 24932) -= 256;
    if (*(int *)(obj + 24932) <= 0) {
        if (*(unsigned char *)(obj + 1557) == 0) {
            func_80099D70(obj + 20220, 0, 0.0f);
        }
        old = *(int *)(obj + 24976);
        *(int *)(obj + 24932) = 0x9600;
        *(unsigned char *)(obj + 1551) = 5;
        func_8001D5D8(&D_800F1AE0, old, 0, 270, 1, 0);
        handle = func_8001D4B8(&D_800F1AE0, 96, 0, -1);
        func_8001D640(&D_800F1AE0, handle, 0);
        func_8001D5D8(&D_800F1AE0, handle, scale_volume(D_800F1AE0.volume, 6553), 120, 0, 0);
        *(int *)(obj + 24980) = handle;
    }
}
