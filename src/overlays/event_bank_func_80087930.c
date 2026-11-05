extern int func_8001D4B8(void *object, int id, int a, int b);
extern void func_8001D640(void *object, int handle, int volume);
extern unsigned char D_800F1AE0[];

void func_80087930(unsigned char *object)
{
    unsigned char *sound;
    int handle;

    if (object[21620] == 0) {
        sound = D_800F1AE0;
        handle = func_8001D4B8(sound, 270, 0, 1);
        func_8001D640(sound, handle, (int)((long long)*(int *)(sound + 104) * 32767) >> 15);
        object[21620] = 1;
    }
}
