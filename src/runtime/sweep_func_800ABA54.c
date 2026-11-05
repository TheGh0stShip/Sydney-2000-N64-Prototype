extern void func_800AB7DC(void *object, int flags);
extern void func_80004380(void *object);

void func_800ABA54(void *object, int flags)
{
    func_800AB7DC(object, 2);
    if (flags & 1) {
        func_80004380(object);
    }
}
