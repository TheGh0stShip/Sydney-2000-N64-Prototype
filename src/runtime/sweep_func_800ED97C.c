extern char D_800FFD30;
extern void func_800E9F2C(void *, int, int, void *);
extern void func_800EA520(void *);
extern void func_800EA638(void *);

void func_800ED97C(char *object)
{
    func_800EA638(&D_800FFD30);
    func_800EA520(object);
    func_800E9F2C(object + 220, 8, 32, object);
    func_800E9F2C(object + 192, 1, 128, object);
    func_800E9F2C(object + 248, 2, 128, object);
}
