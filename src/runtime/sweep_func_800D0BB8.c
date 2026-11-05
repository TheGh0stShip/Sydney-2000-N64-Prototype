extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern char D_800F1AE0[];

void func_800D0BB8(char *obj, int arg)
{
    int voice;

    *(int *)(obj + 1912) = arg;
    *(signed char *)(obj + 1908) = 10;
    voice = func_8001D4B8(D_800F1AE0, 195, 0, 0);
    func_8001D640(D_800F1AE0, voice,
                  (int)((long long)*(int *)(D_800F1AE0 + 104) * 32767) >> 15);
}
