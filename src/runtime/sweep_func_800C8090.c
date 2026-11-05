extern void func_800C7BE0(void *object);
extern void func_800C8058(void *object);

void func_800C8090(unsigned char *object, int *event)
{
    switch (event[0]) {
    case 5:
        func_800C7BE0(object);
        break;
    case 7:
        func_800C8058(object);
        break;
    }
    *(int *)(object + 16) = event[1];
}
