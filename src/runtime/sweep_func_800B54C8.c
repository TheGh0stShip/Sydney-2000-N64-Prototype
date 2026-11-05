extern void func_800AC718(void *a, void *b);
extern void func_800B48CC(void *object, int value, int flag);
extern void func_800B53EC(void *object);

void func_800B54C8(unsigned char *object, int value, int keep)
{
    func_800AC718(object + 20, object + 380);
    func_800B48CC(object, value, 0);
    func_800AC718(object + 20, object + 396);
    *(int *)(object + 376) = value;
    if (keep == 0) {
        *(int *)(object + 412) = 0;
        func_800B53EC(object);
    }
}
