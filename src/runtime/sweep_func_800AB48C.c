extern void func_80004380(void *object);

void func_800AB48C(void *object, unsigned int flags)
{
    if (flags & 1) {
        func_80004380(object);
    }
}
