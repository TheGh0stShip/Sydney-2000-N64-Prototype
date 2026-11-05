extern int func_8001D4B8(void *object, int id, int a, int b);
extern void func_8001D640(void *object, int handle, int volume);
extern unsigned char D_800F1AE0[];

void func_800878BC(unsigned char *object)
{
    unsigned char *sound;
    int handle;

    if (object[21621] == 0) {
        sound = D_800F1AE0;
        handle = func_8001D4B8(sound, 260, 0, 1);
        func_8001D640(sound, handle, (int)((long long)*(int *)(sound + 104) * 32767) >> 15);
        object[21621] = 1;
    }
}
