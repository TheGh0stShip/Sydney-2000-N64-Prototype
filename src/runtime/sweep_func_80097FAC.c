extern void func_80096C8C(int a, int b, float c, float *v, int d, int e);

void func_80097FAC(int a, int b, float c, int *in, int d)
{
    float v[3];
    unsigned int i;

    for (i = 0; i < 3; i++) {
        v[i] = in[i];
    }
    func_80096C8C(a, b, c, v, d, 0);
}
