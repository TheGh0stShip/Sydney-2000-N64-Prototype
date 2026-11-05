extern void func_80074874(void *object, int mode);
extern float func_8007BB9C(int value);
extern void func_80074C58(void *object, float value);

void func_800A7E50(unsigned char *object)
{
    func_80074874(object, 1);
    func_80074C58(object, func_8007BB9C(*(int *)(object + 12212)));
}
