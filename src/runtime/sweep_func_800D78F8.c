extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern char D_800F1AE0[];

void func_800D78F8(char *obj)
{
    float limit;
    int voice;

    *(float *)(obj + 160) -= 28.2f;
    limit = *(float *)(obj + 10844);
    if (*(float *)(obj + 160) <= limit) {
        *(float *)(obj + 160) = limit;
        *(int *)(obj + 10848) = 0;
        if (*(int *)(obj + 10860) != -1) {
            voice = func_8001D4B8(D_800F1AE0, *(int *)(obj + 10860), 0, 0);
            func_8001D640(D_800F1AE0, voice,
                          (int)((long long)*(int *)(D_800F1AE0 + 104) * 32767) >> 15);
        }
    }
}
