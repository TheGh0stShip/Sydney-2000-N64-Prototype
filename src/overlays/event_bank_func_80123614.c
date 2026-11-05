extern void func_800C95C0(void *object, int mode, int value,
                         unsigned char type, int extra);
extern void func_800AC37C(void *object, void *owner);

void func_80123614(unsigned char *object, int value, unsigned char type)
{
    unsigned char *part = object + 9624;
    func_800C95C0(part, 1, value, type, 0);
    func_800AC37C(part, object);
    *(unsigned int *)(object + 13524) |= 8;
}
