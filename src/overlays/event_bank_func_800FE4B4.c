void func_800FE4B4(unsigned char *object)
{
    unsigned char *entry = object + 0x2E0;
    int count = 25;

    do {
        *entry++ = 0;
    } while ((unsigned char)--count != 0);
}
