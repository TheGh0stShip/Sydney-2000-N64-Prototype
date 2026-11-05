extern char D_800882E0[];
extern char D_800882EC[];
extern char D_800882F8[];
extern char D_80088304[];
extern char D_80088310[];
extern char D_8008831C[];
extern char D_80088328[];
extern char D_80088334[];

void func_800ADC10(void);
int func_8000EB20(char *name);

unsigned short func_800C0998(void *obj, unsigned short id)
{
    switch (id) {
    case 0:
        return 0xFFFF;
    case 1:
        return func_8000EB20(D_800882E0);
    case 2:
        return func_8000EB20(D_800882EC);
    case 3:
        func_800ADC10();
        return func_8000EB20(D_800882F8);
    case 4:
        return func_8000EB20(D_80088304);
    case 5:
        return func_8000EB20(D_80088310);
    case 6:
        return func_8000EB20(D_80088328);
    case 7:
        return func_8000EB20(D_80088334);
    case 8:
        return func_8000EB20(D_8008831C);
    default:
        return 0;
    }
}
