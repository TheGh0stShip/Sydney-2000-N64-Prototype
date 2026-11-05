extern void func_800E5788(void *object);
extern void func_800AC334(void *object);
extern void func_800A69E8(void *object);
extern void func_800A6334(void *object);

void func_80117F20(unsigned char *object)
{
    unsigned char *part = object + 196;
    func_800E5788(part);
    func_800AC334(part);
    part = object + 736;
    func_800A69E8(part);
    func_800AC334(part);
    func_800A6334(object);
}
