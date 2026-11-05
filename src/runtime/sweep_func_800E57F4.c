extern void func_8008BCD0(void);
extern void func_800AC3D4(void *);
extern void func_800ADED4(void *);

void *func_800E57F4(char *object)
{
    func_800AC3D4(object);
    *(void (**)(void))(object + 180) = func_8008BCD0;
    func_800ADED4(object + 192);
    return object;
}
