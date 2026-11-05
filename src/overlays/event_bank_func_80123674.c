extern void func_800C95C0(void *object, int mode, int value,
                         unsigned char type, int extra);
extern void func_800AC37C(void *object, void *owner);

void func_80123674(unsigned char *object, int value, unsigned char type,
                   int extra)
{
    unsigned char *part = object + 10248;
    func_800C95C0(part, 0, value, type, extra);
    func_800AC37C(part, object);
    *(unsigned int *)(object + 13524) |= 4;
}
