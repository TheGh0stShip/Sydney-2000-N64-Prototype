extern void func_800C8574(void *object, int delta);
extern void func_800C8500(void *object);

void func_800C8714(unsigned char *object, int *event)
{
    int delta = (event[1] - *(int *)(object + 16)) >> 8;

    switch (event[0]) {
    case 5:
        if (object[777] != 0) {
            func_800C8574(object, delta);
        }
        break;
    case 7:
        func_800C8500(object);
        break;
    }
    *(int *)(object + 16) = event[1];
}
