extern void func_800AC718(void *a, void *b);
extern void func_800B48CC(void *object, int value, int flag);
extern void func_800B6454(void *object);

void func_800B6530(unsigned char *object, int value, int keep)
{
    func_800AC718(object + 20, object + 396);
    func_800B48CC(object, value, 0);
    func_800AC718(object + 20, object + 412);
    *(int *)(object + 376) = value;
    if (keep == 0) {
        *(int *)(object + 428) = 0;
        func_800B6454(object);
    }
}
