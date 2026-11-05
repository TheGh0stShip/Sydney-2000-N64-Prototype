extern void func_8008A168(void);
extern void func_800AC3A4(void *, void *);
extern void func_800AE4D8(void *, int);

void func_800D5AA4(char *object, void *argument)
{
    *(void (**)(void))(object + 180) = func_8008A168;
    func_800AE4D8(object + 220, 2);
    func_800AC3A4(object, argument);
}
