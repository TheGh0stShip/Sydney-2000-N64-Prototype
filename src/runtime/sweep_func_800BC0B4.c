extern unsigned char D_800F2A70[13][8];

void func_800BC0B4(void)
{
    unsigned char n;
    unsigned char *p;

    p = D_800F2A70[0];
    n = 13;
    while (1) {
        if (n == 0) {
            break;
        }
        n--;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p += 8;
    }
}
