extern void func_80019488(void *object, int model);
extern void func_8001A210(void *object, float a, float b, float c, float d, int e);
extern void func_8001A160(void *object, int v);
extern int D_800F6400[];

void func_800CE6C4(void *object, unsigned char index)
{
    func_80019488(object, D_800F6400[index]);
    func_8001A210(object, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_8001A160(object, 32);
}
