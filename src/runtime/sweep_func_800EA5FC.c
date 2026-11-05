extern unsigned char D_800FFD30;
extern unsigned char D_800F26F4;
extern void func_800AC308(void *object);
extern void func_800AB934(void *allocator, void *object);

void func_800EA5FC(unsigned char *object)
{
    func_800AC308(&D_800FFD30);
    func_800AB934(&D_800F26F4, object);
}
