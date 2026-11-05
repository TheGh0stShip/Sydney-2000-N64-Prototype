extern unsigned char D_80088408[];
extern void func_800ADDA4(void *object);

void func_800C0BC8(unsigned char *object)
{
    *(void **)(object + 180) = D_80088408;
    func_800ADDA4(object);
}
