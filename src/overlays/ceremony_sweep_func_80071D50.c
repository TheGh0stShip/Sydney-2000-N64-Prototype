extern int func_8007A760(int, int);
extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
extern void func_8001D5D8(void *, int, int, int, int, int);
extern char *D_800FC270;
extern char D_800F1AE0[];

void func_80071D50(char *obj, int kind)
{
    int bank;
    int voice;

    bank = *(int *)(D_800FC270 + 3372);
    *(int *)(obj + 252) = 0;
    if (kind == 11) {
        kind = 12;
    }
    *(int *)(obj + 252) = func_8007A760(kind, bank);
    voice = func_8001D4B8(D_800F1AE0, 95, 0, 0);
    func_8001D640(D_800F1AE0, voice,
                  (int)((long long)*(int *)(D_800F1AE0 + 104) * 32767) >> 15);
    func_8001D5D8(D_800F1AE0, voice, 0, 870, 1, 0);
}
