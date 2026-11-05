extern void func_8008BCD0(void);
extern void func_800AC3A4(void *, void *);
extern void func_800ADE84(void *, int);

void func_800E57A4(char *object, void *argument)
{
    *(void (**)(void))(object + 180) = func_8008BCD0;
    func_800ADE84(object + 192, 2);
    func_800AC3A4(object, argument);
}
