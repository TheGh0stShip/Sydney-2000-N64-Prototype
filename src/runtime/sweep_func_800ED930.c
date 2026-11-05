extern unsigned char D_800FFD30;
extern void func_800EA184(void *object);
extern void func_800EA4B0(void *object);
extern void func_800EA5FC(void *object);

void func_800ED930(unsigned char *object)
{
    func_800EA184(object + 220);
    func_800EA184(object + 192);
    func_800EA184(object + 248);
    func_800EA4B0(object);
    func_800EA5FC(&D_800FFD30);
}
