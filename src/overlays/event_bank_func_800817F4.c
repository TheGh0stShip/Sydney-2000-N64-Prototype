extern unsigned char D_80071570[];
extern void func_80004380(void *object, int flags);

void func_800817F4(unsigned char *object, int flags)
{
    *(void **)(object + 24) = D_80071570;
    flags &= 1;
    if (flags) {
        func_80004380(object, flags);
    }
}
