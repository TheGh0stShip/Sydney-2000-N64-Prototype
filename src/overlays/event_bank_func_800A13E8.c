extern unsigned char D_80071338[];
extern void func_80004380(void *object);

void func_800A13E8(unsigned char *object, int mode)
{
    *(void **)(object + 24) = D_80071338;
    if (mode & 1) {
        func_80004380(object);
    }
}
