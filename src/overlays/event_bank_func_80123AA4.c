extern void func_800C9E6C(void *object);
extern void func_800CA5AC(void *object);

void func_80123AA4(unsigned char *object)
{
    *(int *)(object + 11012) = -1;
    if (*(int *)(object + 13524) & 4) {
        func_800C9E6C(object + 10248);
    }
    if (*(int *)(object + 13524) & 8) {
        func_800C9E6C(object + 9624);
    }
    if (*(int *)(object + 13524) & 2) {
        func_800CA5AC(object + 4996);
    }
    *(int *)(object + 13524) |= 16;
}
