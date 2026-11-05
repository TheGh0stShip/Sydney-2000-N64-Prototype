extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_8001D5D8(void *, int, int, int, int, int);
extern char D_800F1AE0[];

void func_800A081C(char *obj)
{
    int voice;

    if (*(int *)(obj + 24112) == -1) {
        voice = func_8001D4B8(D_800F1AE0, 211, 0, -1);
        func_8001D640(D_800F1AE0, voice, 0);
        func_8001D5D8(D_800F1AE0, voice,
                      (int)((long long)*(int *)(D_800F1AE0 + 104) * 16383) >> 15,
                      75, 0, 0);
        *(int *)(obj + 24112) = voice;
    }
    *(int *)(obj + 24116) = 22100;
    *(signed char *)(obj + 24120) = 4;
}
