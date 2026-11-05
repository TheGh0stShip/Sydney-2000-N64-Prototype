extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_8001D5D8(void *, int, int, int, int, int);
extern char *D_800FC270;
extern char D_800F1AE0[];

void func_800DAF34(char *obj)
{
    char *game;
    int voice;

    game = D_800FC270;
    if (*(int *)(game + 2560) != 6 && *(int *)(game + 2564) != 0 &&
        *(int *)(obj + 24988) == -1) {
        voice = func_8001D4B8(D_800F1AE0, 213, 0, 0);
        func_8001D640(D_800F1AE0, voice, 0);
        func_8001D5D8(D_800F1AE0, voice,
                      (int)((long long)*(int *)(D_800F1AE0 + 104) * 32767) >> 15,
                      75, 0, 0);
        *(int *)(obj + 24988) = voice;
    }
}
