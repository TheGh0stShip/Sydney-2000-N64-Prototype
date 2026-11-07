extern float func_8002E810(float);
extern float func_8002EFF0(float);
void func_800AD58C(float *m, float a, float b, float c)
{
    float sa = func_8002E810(a);
    float ca = func_8002EFF0(a);
    float sb = func_8002E810(b);
    float cb = func_8002EFF0(b);
    float sc = func_8002E810(c);
    float cc = func_8002EFF0(c);
    m[0] = sa * sc + ca * cb * cc;
    m[1] = sb * cc;
    m[2] = sa * cb * cc - ca * sc;
    m[4] = ca * cb * sc - sa * cc;
    m[5] = sb * sc;
    m[6] = ca * cc + sa * cb * sc;
    m[8] = ca * sb;
    m[9] = -cb;
    m[10] = sa * sb;
}
