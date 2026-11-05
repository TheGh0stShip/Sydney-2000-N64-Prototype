extern unsigned char D_800F26F4;
extern void func_800E4234(void *object);
extern void func_800E8EB4(void *object);
extern void func_800AC308(void *object);
extern void func_800AB934(void *allocator, void *object);

void func_800E99E0(unsigned char *object)
{
    func_800E4234(object + 3412);
    func_800E8EB4(object);
    func_800AC308(object);
    func_800AB934(&D_800F26F4, object);
    *(void **)(object + 644) = 0;
}
