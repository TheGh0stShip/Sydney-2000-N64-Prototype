typedef struct {
    float x, y, z;
} Vec3f;

extern Vec3f D_80074330;
extern void func_800AD434(void *, float, int);
extern void func_800AD9E8(void *);
extern void func_800A851C(void *, int, void *, void *);
extern void func_800A848C(void *, int, int);
extern void func_800B3870(void *, void *, int);
extern void func_800A9BE8(void *, int);
extern void func_800AC334(void *);

void func_800752A4(char *self)
{
    int n;
    int t;
    float one;
    float a, b, c;
    float *m;
    float *m2;

    m = (float *)(self + 1356);
    n = 3;
    t = *(int *)(self + 280);
    one = *(float *)0x80071700;
    m2 = (float *)(self + 3376);
    *(unsigned char *)(self + 10336) = n;
    *(int *)(self + 10340) = 0x12C00;
    *(int *)(self + 3552) = t;
    ((int *)m)[9] = 0;
    ((int *)m)[8] = 0;
    ((int *)m)[6] = 0;
    ((int *)m)[4] = 0;
    ((int *)m)[2] = 0;
    ((int *)m)[1] = 0;
    ((int *)m)[18] = 0;
    ((int *)m)[17] = 0;
    ((int *)m)[16] = 0;
    m[10] = one;
    m[5] = one;
    m[0] = one;
    ((int *)m2)[9] = 0;
    ((int *)m2)[8] = 0;
    ((int *)m2)[6] = 0;
    ((int *)m2)[4] = 0;
    ((int *)m2)[2] = 0;
    ((int *)m2)[1] = 0;
    ((int *)m2)[18] = 0;
    ((int *)m2)[17] = 0;
    ((int *)m2)[16] = 0;
    m2[10] = one;
    m2[5] = one;
    m2[0] = one;
    func_800AD434(m, 3.8397238f, n);
    a = *(float *)0x80071704;
    b = *(float *)0x80071708;
    c = *(float *)0x8007170C;
    *(float *)(self + 1420) = a;
    *(float *)(self + 1428) = b;
    *(float *)(self + 1424) = c;
    ((Vec3f *)(m2 + 16))->x = D_80074330.x;
    ((Vec3f *)(m2 + 16))->y = D_80074330.y;
    ((Vec3f *)(m2 + 16))->z = D_80074330.z;
    func_800AD9E8(self + 3356);
    func_800A851C(self + 500, 0, self + 3356, m);
    func_800A848C(self + 500, 0, 32);
    func_800B3870(self + 3188, m, 76);
    func_800A9BE8(self + 4660, 7);
    func_800AC334(self + 3168);
}
