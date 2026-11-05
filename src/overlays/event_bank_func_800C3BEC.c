extern int func_800B9BD4(void *a, int b, void *c, void *d, void *e, int f);
extern void func_800B9E9C(void *a, int b, int c, float d, int e);
extern void func_800B9964(void *a, void *b, void *c, void *d);

void func_800C3BEC(char *obj, int b)
{
    char v24[16];
    char v40[16];
    char v56[8];

    if (func_800B9BD4(obj + 4552, b, v24, v56, v40, 0)) {
        *(int *)(obj + 19396) = 0;
        func_800B9E9C(obj + 4552, 0, -1, 1.0f, 0);
    }
    func_800B9964(obj + 4552, v24, v56, v40);
}
