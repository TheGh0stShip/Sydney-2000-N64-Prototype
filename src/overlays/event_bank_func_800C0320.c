extern int D_800724D0;
extern unsigned short D_800724D4[];

void func_800C0320(void)
{
    unsigned int i;
    int v;
    int a, b, c;

    if (D_800724D0 == 0) {
        v = 0;
        for (i = 0; i < 384; i += 6) {
            a = v + 3;
            b = v + 1;
            c = v + 2;
            D_800724D4[i + 0] = v;
            v += 4;
            D_800724D4[i + 1] = D_800724D4[i + 4] = a;
            D_800724D4[i + 2] = D_800724D4[i + 3] = b;
            D_800724D4[i + 5] = c;
        }
        D_800724D0 = 1;
    }
}
