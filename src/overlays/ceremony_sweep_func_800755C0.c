typedef struct {
    float x, y, z;
} Vec3f;

extern Vec3f D_800742D0;
extern void func_800ADC38(void *);
extern void func_800B9FA4(void *, int, int, float, int, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern void func_800B3870(void *, void *, int);
extern void func_800A9BE8(void *, int);

void func_800755C0(char *self)
{
    char *anim = self + 2764;
    char *pos;
    float k;
    Vec3f *dst;

    func_800ADC38(anim);
    func_800ADC38(self + 4204);
    func_800ADC38(self + 4416);
    k = *(float *)0x80071750;
    func_800B9FA4(anim, 0, -1, k, 0, 0);
    func_800B9E9C(anim, 0, -1, k, 0);
    pos = self + 2784;
    ((Vec3f *)(pos + 64))->x = D_800742D0.x;
    ((Vec3f *)(pos + 64))->y = D_800742D0.y;
    ((Vec3f *)(pos + 64))->z = D_800742D0.z;
    *(float *)(self + 2852) -= *(float *)0x80071754;
    dst = (Vec3f *)(self + 3132);
    dst->x = ((Vec3f *)(pos + 64))->x;
    dst->y = ((Vec3f *)(pos + 64))->y;
    dst->z = ((Vec3f *)(pos + 64))->z;
    func_800B3870(self + 3188, pos, 76);
    *(unsigned char *)(self + 10336) = 5;
    *(int *)(self + 10340) = 0xD200;
    func_800A9BE8(self + 4660, 1);
}
