extern void func_800B9FA4(void *object, int id, int second, float value, int fourth, int fifth);
extern void func_800B9E9C(void *object, int id, int second, float value, int fourth);

void func_80123DD0(unsigned char *object, int id, float value)
{
    func_800B9FA4(object + 4552, id, -1, value, 0, 1);
    func_800B9E9C(object + 4552, id, -1, value, 0);
}
