extern void func_800B9E9C(void *object, int a, int b, float c, int d);
extern void func_800B9E74(void *object, int a);
extern void func_800B9A68(void *object, int a);

void func_800B7CB0(unsigned char *object)
{
    unsigned char *timer = object + 4552;

    func_800B9E9C(timer, 3, -1, 2.0f, 0);
    func_800B9E74(timer, 10);
    func_800B9A68(timer, 2560);
    object[17591] = 1;
    object[17588] = 0;
    object[17589] = 0;
    object[17592] = 1;
}
