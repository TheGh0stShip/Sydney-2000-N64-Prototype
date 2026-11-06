void func_8011F4E0(char *obj)
{
    int v = *(int *)(obj + 0x10A4) - 150;
    double d = (double)v;
    float t, u, five, b;

    if (v < 0)
        d += *(double *)0x80080C38;
    t = (float)d;
    t = t / *(float *)0x80080C40;
    u = *(float *)0x80080C44 - t;
    t = t * *(float *)0x80080C48;
    five = *(float *)0x80080C4C;
    u = u * five;
    t = t + *(float *)0x80080C50;
    *(float *)(obj + 0x10AC) = *(float *)0x80080C54;
    b = *(float *)0x80080C5C;
    *(float *)(obj + 0x10BC) = *(float *)0x80080C58;
    *(float *)(obj + 0x10C0) = t;
    *(float *)(obj + 0x10B0) = (u + five) / b;
}
