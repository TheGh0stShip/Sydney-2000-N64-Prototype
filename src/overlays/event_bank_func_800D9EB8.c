typedef struct {
    char pad[104];
    int volume;
} SoundPlayer;

extern SoundPlayer D_800F1AE0;
extern void func_8001D5D8(SoundPlayer *sp, int handle, int vol, int fade, int a, int b);
extern int func_8001D4B8(SoundPlayer *sp, int id, int a, int loop);
extern void func_8001D640(SoundPlayer *sp, int handle, int vol);

static inline int scale_volume(int volume, int factor)
{
    return (volume * factor) >> 15;
}

void func_800D9EB8(char *obj)
{
    int handle;
    int old = *(int *)(obj + 24980);

    *(int *)(obj + 24984) = -1;
    *(int *)(obj + 24988) = -1;
    *(int *)(obj + 24992) = -1;
    func_8001D5D8(&D_800F1AE0, old, 0, 15, 1, 0);
    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 213, 0, 1),
                  scale_volume(D_800F1AE0.volume, 32767));
    handle = func_8001D4B8(&D_800F1AE0, 109, 0, -1);
    func_8001D640(&D_800F1AE0, handle, 0);
    func_8001D5D8(&D_800F1AE0, handle, scale_volume(D_800F1AE0.volume, 26213), 45, 0, 0);
    *(int *)(obj + 24984) = handle;
}
