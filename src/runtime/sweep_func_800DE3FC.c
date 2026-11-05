extern void func_800E8EB4(void *object);
extern void func_800C4008(void);

void func_800DE3FC(unsigned char *object)
{
    func_800E8EB4(*(void **)(object + 188));
    func_800C4008();
}
