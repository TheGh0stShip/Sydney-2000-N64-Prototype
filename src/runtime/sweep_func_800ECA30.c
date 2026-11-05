extern char D_800FFD30;
extern void func_800AC308(void *);
extern void func_800EA184(void *);
extern void func_800EA4B0(void *);

void func_800ECA30(char *object)
{
    func_800EA184(object + 216);
    func_800EA184(object + 244);
    func_800EA4B0(object);
    func_800AC308(&D_800FFD30);
}
