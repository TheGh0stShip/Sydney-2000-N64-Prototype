extern int func_80019680(void *object, const char *name);
extern void func_8001A1D8(void *object, float a, float b, float c, float d);
extern void func_800191E0(void *object, int v);

void func_800CE734(void *object, float x, float y)
{
    if (func_80019680(object, "BRITAIN_FLAG") == 0) {
        func_8001A1D8(object, 0.0f, 0.0f, x, y);
        func_800191E0(object, -1);
    }
}
