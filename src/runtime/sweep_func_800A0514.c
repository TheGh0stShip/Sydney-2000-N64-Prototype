extern void func_800AD9E8();

void func_800A0514(unsigned char *object, int *message)
{
    switch (message[0]) {
    case 3:
        break;
    case 5:
        func_800AD9E8();
        break;
    }
    *(int *)(object + 16) = message[1];
}
