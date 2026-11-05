extern unsigned char D_80084208[];
extern void func_80004380(void *object);

void func_80096718(unsigned char *object, int flags)
{
    *(void **)(object + 24) = D_80084208;
    if (flags & 1) {
        func_80004380(object);
    }
}
