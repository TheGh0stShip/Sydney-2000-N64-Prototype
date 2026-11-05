unsigned int func_800DB0CC(const unsigned short *text)
{
    unsigned int length = 0;
    while (*text != 0) {
        text++;
        length++;
    }
    return (unsigned short)length + 1;
}
