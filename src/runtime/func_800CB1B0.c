void func_800CB1B0(unsigned char *object)
{
    unsigned char index = 0;
    int mask = -5;

loop:
    if (index < 5) {
        unsigned char *entry = (unsigned char *)(index * 212 + (unsigned int)object + 0x75C);
        *(int *)(entry + 0xC0) &= mask;
        index++;
        goto loop;
    }
}
