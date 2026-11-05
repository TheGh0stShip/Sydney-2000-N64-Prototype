extern void func_800EC3D0(void *object, void *value);
extern void func_800E9D10(void *object);

void func_800EC9F4(unsigned char *object, const int *event)
{
    if (event[0] == 5) {
        func_800EC3D0(object, object + 244);
        func_800E9D10(object);
    }
}
