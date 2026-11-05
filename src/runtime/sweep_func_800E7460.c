extern unsigned char D_80103500[];

void func_800E7460(int unused, int start, int width, int height)
{
    unsigned char *p = D_80103500;
    int v = start;
    unsigned char i;

    height -= 2;
    *p++ = (height + width) * 2 + 1;
    for (i = 0; i < (unsigned char)width; i++) {
        *p++ = v;
        v++;
    }
    v += 8;
    for (i = 0; i < (unsigned char)height; i++) {
        *p++ = v;
        v += 9;
    }
    for (i = 0; i < (unsigned char)width; i++) {
        *p++ = v;
        v--;
    }
    v -= 8;
    for (i = 0; i < (unsigned char)height; i++) {
        *p++ = v;
        v -= 9;
    }
    *p = start;
}
