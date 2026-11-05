extern unsigned char *D_800FC270;
extern unsigned char D_800FC274;
extern unsigned char D_800FC275;
extern char D_8008AB3C[];
extern char D_8008AB68[];
extern char D_8008AB84[];
extern void func_800AAA60(char *file, int line, char *message);

void func_800DA720(void)
{
    D_800FC270[3410] &= 0xF8;

    switch (D_800FC274) {
    case 0:
        D_800FC270[3410] |= 3;
        break;
    case 1:
        D_800FC270[3410] |= 1;
        break;
    case 2:
        break;
    default:
        func_800AAA60(D_8008AB3C, 2336, D_8008AB68);
        break;
    }

    if (D_800FC275 == 0) {
        D_800FC270[3410] |= 4;
    } else if (D_800FC275 != 1) {
        func_800AAA60(D_8008AB3C, 2344, D_8008AB84);
    }
}
