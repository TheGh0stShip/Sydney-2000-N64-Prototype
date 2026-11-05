extern void func_800AC334(void *object);
extern void func_800A8850(void *object);

void func_80126E20(unsigned char *object)
{
    if (object[426] != 4) {
        func_800AC334(object + 1048);
        func_800A8850(object + 1048);
    }
}
