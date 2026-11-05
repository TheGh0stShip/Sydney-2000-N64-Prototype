extern void func_800A3218(void *object);
extern void func_8001D550(void *object, int mode);
extern void func_8001D9A0(void);
extern void func_800A30AC(void *object);

int func_800A3240(unsigned char *object)
{
    if (*(int *)(object + 84) == 10) {
        return 1;
    }
    func_800A3218(object);
    func_8001D550(object, 3);
    func_8001D9A0();
    func_800A30AC(object);
    return 1;
}
