extern void func_800A0ECC();

void func_800A0F48(unsigned char *object, int *message)
{
    switch (message[0]) {
    case 3:
        break;
    case 5:
        if (*(int *)(object + 484) & 1) {
            func_800A0ECC(object);
        }
        break;
    }
    *(int *)(object + 16) = message[1];
}
