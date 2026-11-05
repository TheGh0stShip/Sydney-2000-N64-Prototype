extern void func_80004380(void *object);

void func_800AF064(void *object, int flags)
{
    if (flags & 1) {
        func_80004380(object);
    }
}
