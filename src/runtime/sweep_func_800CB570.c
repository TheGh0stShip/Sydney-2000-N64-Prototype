extern void func_8000F43C(unsigned short, int);

void func_800CB570(char *object, float amount)
{
    float scaled = (1.0f - amount) * 0.07692299783229828f;

    if (scaled == 0.0f) {
        scaled = 0.009999999776482582f;
    }
    func_8000F43C(*(unsigned short *)(object + 3166),
                  (int)(scaled * 7680.0f));
}
