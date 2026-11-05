extern unsigned char D_80071568[];
extern void func_80004380(void *object);

void func_800B67DC(unsigned char *object, int flags)
{
    *(void **)(object + 24) = D_80071568;
    if (flags & 1) {
        func_80004380(object);
    }
}
