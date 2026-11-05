extern unsigned char D_8008C4C0;
extern void func_80004380(void *object);

void func_800EBFD4(unsigned char *object, unsigned int enabled)
{
    *(void **)(object + 24) = &D_8008C4C0;
    if ((enabled & 1) != 0) {
        func_80004380(object);
    }
}
