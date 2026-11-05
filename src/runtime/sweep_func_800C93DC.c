extern void func_800C8C40(void);
extern void func_800C9230(void *object);

void func_800C93DC(unsigned char *object, int *event)
{
    if (event[0] == 5 && *(unsigned short *)(object + 186) == 1) {
        func_800C8C40();
        func_800C9230(object);
    }
    *(int *)(object + 16) = event[1];
}
