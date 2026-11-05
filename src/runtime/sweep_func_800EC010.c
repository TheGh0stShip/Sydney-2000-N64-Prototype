extern char D_800FFD30[];
extern void func_800EA638(void *);
extern void func_800EA520(void *);
extern unsigned short func_8000EB20(const char *);
extern void func_80015F98(void *, float, float, unsigned short);
extern void func_800E9F2C(void *, int, int, void *);

typedef struct Effects {
    char pad[192];
    void *sounds[6];
    char groupA[28];
    char groupB[28];
} Effects;

void func_800EC010(Effects *fx)
{
    unsigned int i;

    func_800EA638(D_800FFD30);
    func_800EA520(fx);
    for (i = 0; i < 6; i++) {
        fx->sounds[i] = 0;
    }
    func_80015F98(&fx->sounds[0], 29.4903011f, 29.4903011f, func_8000EB20("SKEET_SMOKE"));
    func_80015F98(&fx->sounds[1], 81.9174957f, 81.9174957f, func_8000EB20("SKEET_SMASH1"));
    func_80015F98(&fx->sounds[2], 32.7669983f, 32.7669983f, func_8000EB20("SKEET_SMASH2"));
    func_80015F98(&fx->sounds[3], 9.83010006f, 9.83010006f, func_8000EB20("SKEET_BIT1"));
    func_80015F98(&fx->sounds[4], 4.91505003f, 4.91505003f, func_8000EB20("SKEET_BIT2"));
    func_80015F98(&fx->sounds[5], 1.63835001f, 1.63835001f, func_8000EB20("SKEET_BIT3"));
    func_800E9F2C(fx->groupA, 16, 32, fx);
    func_800E9F2C(fx->groupB, 2, 64, fx);
}
