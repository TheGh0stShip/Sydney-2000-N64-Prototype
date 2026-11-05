extern void func_800E9744(void *object);
extern void func_8001A248(void *object);

void func_800E9794(unsigned char *object)
{
    *(int *)(object + 29364) = -1;
    func_800E9744(object);
    if (*(void **)(object + 27652) != 0) {
        func_8001A248(object + 27652);
    }
}
