extern unsigned char *D_800FC270;
extern void func_800E287C(void *object, int mode);
extern void func_800DFFF4(void *object, int mode);

void func_800E434C(unsigned char *object, int mode)
{
    if (mode >= 9 && (mode < 11 || mode == 39)) {
        if (D_800FC270[1266] != 0) {
            func_800E287C(object, 0);
        } else {
            func_800DFFF4(object, 0);
        }
        if (mode != 39) {
            object[19102] = 1;
        }
    }
}
