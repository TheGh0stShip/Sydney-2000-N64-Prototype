extern void *D_800FCB5C[13];
extern void func_8001A248(void **slot);

void func_800DAFBC(void) {
    unsigned int i;

    for (i = 0; i < 13; i++) {
        if (D_800FCB5C[i] != 0) {
            func_8001A248(&D_800FCB5C[i]);
        }
    }
}
