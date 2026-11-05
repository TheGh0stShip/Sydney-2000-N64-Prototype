extern void func_80004380(void *object);
extern unsigned char D_80071480[];

void func_8008880C(unsigned char *object, int flags)
{
    *(void **)(object + 24) = D_80071480;
    if (flags & 1) {
        func_80004380(object);
    }
}
