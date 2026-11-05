extern char *D_800FC270;
extern unsigned char D_800FC274;
extern unsigned char D_800FC275;

void func_800DAB98(void) {
    if (D_800FC270[0xD52] & 1) {
        if (D_800FC270[0xD52] & 2) {
            D_800FC274 = 0;
        } else {
            D_800FC274 = 1;
        }
    } else {
        D_800FC274 = 2;
    }
    if (D_800FC270[0xD52] & 4) {
        D_800FC275 = 0;
    } else {
        D_800FC275 = 1;
    }
}
