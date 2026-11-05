extern void func_800708F8(void);
extern void func_80081DC8(void *, void *);
extern void func_800ADE84(void *, int);

void func_800CEF00(char *object, void *argument)
{
    *(void (**)(void))(object + 180) = func_800708F8;
    func_800ADE84(object + 17372, 2);
    func_800ADE84(object + 17124, 2);
    func_80081DC8(object, argument);
}
