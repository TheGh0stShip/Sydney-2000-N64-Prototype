void func_800CB160(unsigned char *object)
{
    unsigned char index = 0;

loop:
    if (index < 5) {
        unsigned char *entry = (unsigned char *)(index * 212 + (unsigned int)object + 0x75C);
        *(int *)(entry + 0xC0) |= 4;
        index++;
        goto loop;
    }
}
