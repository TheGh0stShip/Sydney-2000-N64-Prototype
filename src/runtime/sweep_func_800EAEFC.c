extern unsigned char D_8008C300;
extern void func_80004380(void *object);

void func_800EAEFC(unsigned char *object, unsigned int enabled)
{
    *(void **)(object + 24) = &D_8008C300;
    if ((enabled & 1) != 0) {
        func_80004380(object);
    }
}
