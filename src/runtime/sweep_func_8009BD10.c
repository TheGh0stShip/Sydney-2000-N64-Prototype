extern void func_800B33E8(float value, int a, int b, int c);

void func_8009BD10(float value, int raw, unsigned short a, int b, int c)
{
    if (raw == 0) {
        value = value / 100.0f;
    }
    func_800B33E8(value, a, b, c);
}
