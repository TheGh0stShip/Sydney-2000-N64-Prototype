extern void func_8007492C(void *object, int mode);
extern float func_8007B04C(int value);
extern void func_80074DAC(void *object, float value);
extern void func_80075050(void *object);

void func_8008F28C(unsigned char *object)
{
    func_8007492C(object, 1);
    func_80074DAC(object, func_8007B04C(*(int *)(object + 23004)));
    func_80075050(object);
}
