extern void func_800A2B3C(void *object);

void func_800A2BB8(unsigned char *object, int *message)
{
    unsigned char *part;

    switch (message[0]) {
    case 3:
        break;
    case 5:
        part = object + 240;
        if (*(int *)(part + 240) & 1) {
            func_800A2B3C(object);
            *(int *)(part + 240) &= ~1;
        }
        break;
    }
    *(int *)(object + 16) = message[1];
}
