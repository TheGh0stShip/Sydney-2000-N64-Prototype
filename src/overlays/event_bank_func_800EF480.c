#define D_80078BB0 (*(float *)0x80078BB0)

extern void func_800B8C70(unsigned char *object, float value);

void func_800EF480(unsigned char *object, float lo, float hi)
{
    float t = *(float *)(object + 800) * *(float *)(object + 816);

    if (0.0f < t) {
        t *= hi - lo;
        t += lo;
    }
    if (*(int *)(object + 764) != 0) {
        t = D_80078BB0;
    }
    *(float *)(object + 632) = t;
    func_800B8C70(object, t);
}
