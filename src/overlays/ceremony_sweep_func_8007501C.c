typedef struct {
    float x, y, z;
} Vec3f;

extern Vec3f D_800742DC;
extern void func_800ADC38(void *);
extern void func_800B9FA4(void *, int, int, float, int, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern void func_800AD9E8(void *);
extern void func_800A9BE8(void *, int);

void func_8007501C(char *self)
{
    float k;
    char *pos;
    float *m;
    Vec3f *dst;
    Vec3f *dst2;

    *(unsigned char *)(self + 10336) = 7;
    *(int *)(self + 10340) = 0xF000;
    func_800ADC38(self + 4204);
    k = *(float *)0x800716D8;
    *(int *)(self + 4400) = *(int *)(self + 268);
    func_800B9FA4(self + 2764, 2, -1, k, 0, 0);
    func_800B9E9C(self + 2764, 2, -1, k, 0);
    pos = self + 2784;
    ((Vec3f *)(pos + 64))->x = D_800742DC.x;
    ((Vec3f *)(pos + 64))->y = D_800742DC.y;
    ((Vec3f *)(pos + 64))->z = D_800742DC.z;
    dst = (Vec3f *)(self + 3132);
    dst->x = ((Vec3f *)(pos + 64))->x;
    dst->y = ((Vec3f *)(pos + 64))->y;
    dst->z = ((Vec3f *)(pos + 64))->z;
    m = (float *)(self + 4224);
    ((int *)m)[9] = 0;
    ((int *)m)[8] = 0;
    ((int *)m)[6] = 0;
    ((int *)m)[4] = 0;
    ((int *)m)[2] = 0;
    ((int *)m)[1] = 0;
    ((int *)m)[18] = 0;
    ((int *)m)[17] = 0;
    ((int *)m)[16] = 0;
    m[10] = k;
    m[5] = k;
    m[0] = k;
    dst2 = (Vec3f *)(m + 16);
    dst2->x = ((Vec3f *)(pos + 64))->x;
    dst2->y = ((Vec3f *)(pos + 64))->y;
    dst2->z = ((Vec3f *)(pos + 64))->z;
    func_800AD9E8(self + 4204);
    func_800A9BE8(self + 4660, 3);
}
