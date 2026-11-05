extern void func_800A6440(void *object);
extern void func_800A6818(void *object);

void func_800A6A98(unsigned char *object, int *message)
{
    switch (message[0]) {
    case 3:
        func_800A6440(object);
        break;
    case 5:
        func_800A6818(object);
        break;
    case 6:
        break;
    }
    *(int *)(object + 16) = message[1];
}
