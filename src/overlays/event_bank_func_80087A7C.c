extern void func_8001D5D8(void *object, int handle, int a, int b, int c, int d);
extern int func_8001D4B8(void *object, int id, int a, int b);
extern void func_8001D640(void *object, int handle, int volume);
extern unsigned char D_800F1AE0[];

void func_80087A7C(unsigned char *object)
{
    int handle;
    unsigned char *sound = D_800F1AE0;
    int previous = *(int *)(object + 21580);

    *(int *)(object + 21584) = -1;
    *(int *)(object + 21588) = -1;
    *(int *)(object + 21592) = -1;
    func_8001D5D8(sound, previous, 0, 15, 1, 0);
    handle = func_8001D4B8(sound, 109, 0, -1);
    func_8001D640(sound, handle, 0);
    func_8001D5D8(sound, handle,
                  (int)((long long)*(int *)(sound + 104) * 22936) >> 15, 45, 0, 0);
    *(int *)(object + 21584) = handle;
}
