extern unsigned int D_800FFD30;
extern unsigned char D_800F26F4;
extern void func_800AC308(void *object);
extern void func_800AB9B8(void *allocator, void *object);

void func_800EA638(unsigned char *object)
{
    D_800FFD30 = 0;
    func_800AC308(&D_800FFD30);
    func_800AB9B8(&D_800F26F4, object);
}
