extern void func_800B360C(void *object, int value);
extern void func_800B35F0(void *object);

void func_800B36A4(unsigned char *object, int *event)
{
    switch (event[0]) {
    case 5:
        break;
    case 3:
        func_800B360C(object, event[4]);
        break;
    case 7:
        func_800B35F0(object);
        break;
    }
    *(int *)(object + 16) = event[1];
}
