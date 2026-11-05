void func_80079290(unsigned char *object)
{
    /* Preserve the original SN compiler's 16-byte leaf frame. */
    volatile int frame[3];
    *(int *)(object + 0x10D4C) = 1;
}
