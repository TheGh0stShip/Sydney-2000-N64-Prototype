extern unsigned char D_800FFD30;
extern void func_800EA184(void *object);
extern void func_800EA4B0(void *object);
extern void func_800AC308(void *object);

void func_800EAE54(unsigned char *object)
{
    func_800EA184(object + 220);
    func_800EA184(object + 248);
    func_800EA184(object + 276);
    func_800EA184(object + 304);
    func_800EA184(object + 332);
    func_800EA4B0(object);
    func_800AC308(&D_800FFD30);
}
