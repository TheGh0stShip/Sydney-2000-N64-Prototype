void func_800E2114(char *object)
{
    int minimum = 0x4B000;
    unsigned char i;
    char *slot;

    for (i = 0; i < *(unsigned char *)(object + 1555); i++) {
        slot = object + i * 16;
        if (*(short *)(slot + 25098) != 1 &&
            *(int *)(slot + 25088) < minimum) {
            minimum = *(int *)(slot + 25088);
        }
    }
    for (i = 0; i < *(unsigned char *)(object + 1555); i++) {
        slot = object + i * 16;
        if (*(short *)(slot + 25098) != 1) {
            *(int *)(slot + 25092) = *(int *)(slot + 25088) - minimum;
        }
    }
}
