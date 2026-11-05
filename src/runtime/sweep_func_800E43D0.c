extern unsigned char *D_800FC270;
extern void func_800DFB48(void *object, int index);
extern void func_800E287C(void *object, int mode);
extern void func_800DFFF4(void *object, int mode);

void func_800E43D0(unsigned char *object, int mode)
{
    switch (mode) {
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        func_800DFB48(object, mode - 29);
        object[19102] = 1;
        break;
    case 10:
        if (D_800FC270[1266] != 0) {
            func_800E287C(object, 0);
        } else {
            func_800DFFF4(object, 0);
        }
        object[19102] = 1;
        break;
    }
}
