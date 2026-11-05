void func_800DB0F4(unsigned short *dst, unsigned short *src, int n)
{
loop:
    if ((unsigned short)n-- != 0) {
        *dst = *src;
        dst++;
        if (*src == 0) {
            goto loop;
        }
        src++;
        goto loop;
    }
}
